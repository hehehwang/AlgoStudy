# QUADTREE 쿼드 트리 뒤집기
input = __import__('sys').stdin.readline

def upsideDown():
    global ss
    s = ss.pop()
    if s != 'x': return [s]
    else:
        q1, q2, q3, q4 = [upsideDown() for _ in range(4)]
        return ['x']+q3+q4+q1+q2

for _ in range(int(input())):
    sss = input()
    ss = list(reversed(sss))
    print(''.join(upsideDown()))