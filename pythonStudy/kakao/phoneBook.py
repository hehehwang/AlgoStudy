class Node:
    def __init__(self, n, parN):
        self.value = n
        self.isNum = False
        self.child = dict()
        self.pastNums = str(parN)+str(n)

    def __repr__(self):
        return str(self.pastNums)

def solution(phone_book):
    root = Node(-1, -1)
    # brk = False
    for num in phone_book:
        node = root
        for n in num:
            if node.isNum:
                return False
                # print('true')
                # brk = True
                # break
            try : node = node.child[n]
            except:
                node.child[n] = Node(n, node.pastNums)
                node = node.child[n]
        node.isNum = True
        if node.child:
            return False
            # print('true')
            # brk = True
            # break
    return True