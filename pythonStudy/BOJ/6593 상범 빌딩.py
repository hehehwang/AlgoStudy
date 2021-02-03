# 6593 상범 빌딩
from collections import deque
input = __import__('sys').stdin.readline

dz = [0,0,0,0,1,-1]
dr = [0,0,1,-1,0,0]
dc = [1,-1,0,0,0,0]
while 1:
    bZ, bR, bC = map(int, input().split())
    if (bZ+bR+bC)==0: break
    build = []
    for i in range(bZ):
        build.append([list(input().strip()) for _ in range(bR)])
        input()
    vis = [[[0]*bC for _ in range(bR)] for _ in range(bZ)]
    Q = deque([])
    exit = (0, 0, 0)
    for z in range(bZ):
        for i in range(bR):
            for j in range(bC):
                v = build[z][i][j]
                if v == 'S':
                    Q.append((z, i, j))
                    vis[z][i][j] = 1
                elif v == 'E': exit = (z, i, j)
    while Q:
        vz, vr, vc = Q.popleft()
        for i in range(6):
            nz, nr, nc = vz+dz[i], vr+dr[i], vc+dc[i]
            if nz<0 or nr<0 or nc<0 or bZ<=nz or bR<=nr or bC<=nc: continue
            if vis[nz][nr][nc]: continue
            if build[nz][nr][nc] == '#': continue
            Q.append((nz, nr, nc))
            vis[nz][nr][nc] = vis[vz][vr][vc]+1

    v = vis[exit[0]][exit[1]][exit[2]]
    print(f'Escaped in {v-1} minute(s).' if v else 'Trapped!')