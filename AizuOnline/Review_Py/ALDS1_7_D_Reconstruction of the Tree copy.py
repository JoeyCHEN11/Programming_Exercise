NIL = -1
class Node:
    def __init__(self, left = NIL, right = NIL):  
        self.left = left
        self.right = right
        pass
    # def __str__(self):
    #     return f"parent: {self.parent}, left: {self.left}, right: {self.right}"


N = int(input())

pre_order = list(map(int, input().split()))
in_order = list(map(int, input().split()))

Tree = [Node() for _ in range(N + 1)]
in_idx = dict(zip(in_order, range(N)))
pre_pos = 0

def build_from_inorder(left, right):
    global pre_pos
    
    if left >= right: return NIL
    
    root = pre_order[pre_pos]
    pre_pos += 1
    
    mid = in_idx[root]
    l_root = build_from_inorder(left, mid)
    r_root = build_from_inorder(mid + 1, right)
    Tree[root].left = l_root
    Tree[root].right = r_root
    return root

def post_order(root, ans):
    if root == NIL: return
    
    post_order(Tree[root].left, ans)
    post_order(Tree[root].right, ans)
    ans.append(root)
    

root = build_from_inorder(0, N)

ans = []
post_order(root, ans)

print(*ans)