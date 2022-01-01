# 1926 그림
input = __import__('sys').stdin.readline
row, col = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(row)]
visited = [[False]*col for _ in range(row)]
dx, dy = [1, 0, 0, -1], [0, 1, -1, 0]
cnt, area = 0, 0
q = []

for r, line in enumerate(board):
    for c, n in enumerate(line):
        if n and not visited[r][c]:
            q.append((r, c))
            visited[r][c] = True
            a = 0
            while q:
                a += 1
                py, px = q.pop()
                for y, x in zip(dy, dx):
                    cy, cx = py + y, px+x
                    if 0 <= cy < row and 0 <= cx < col and (not visited[cy][cx]) and board[cy][cx]:
                        visited[cy][cx] = True
                        q.append((cy, cx))
            cnt += 1
            area = max(area, a)

print(f'{cnt}\n{area}')