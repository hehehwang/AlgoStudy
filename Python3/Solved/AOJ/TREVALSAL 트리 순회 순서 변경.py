# TRAVERSAL 트리 순회 순서 변경

def printPostOrder(preorder:list, inorder:list):
    # 트리에 포함된 노드 수
    N = len(preorder)
    # 기저 사례 : 텅 빈 트리는 종료
    if not preorder: return
    # 이 트리의 루트는 전위 탐색 결과로부터 바로 알 수 있다.
    root = preorder[0]
    # 이 트리의 왼쪽 서브트리의 크기는 중위 탐색 결과에서 루트의 위치를 찾아서 알 수 있다.
    L = inorder.index(root)
    # 오른쪽 서브트리의 크기는 N에서 왼쪽 서브트리와 루트를 빼면 알 수 있다.
    R = N-1-L

    printPostOrder(preorder[1:L+1], inorder[:L])
    printPostOrder(preorder[L+1:], inorder[L+1:])
    print(root, end=' ')

for _ in range(int(input())):
    input()
    printPostOrder(list(map(int, input().split())),
                   list(map(int, input().split())))
    print()