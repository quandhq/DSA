from node import Node

"""
                              1
                         2        3
                      4    5    6   7

"""

root: Node = Node(1, Node(2, Node(4, None, None), Node(5, None, None)), Node(3, Node(6, None, None), Node(7, None, None)))

class Tree:
    def __init__(self) -> None:
        pass

    @staticmethod
    def postOrderTraversalWithRecursion(root: Node) -> list:    #return list that contain results
        res = []
        if root != None:
            res.extend(Tree.postOrderTraversalWithRecursion(root.leftNode))
            res.extend(Tree.postOrderTraversalWithRecursion(root.rightNode))
            res.append(root.val)
        return res
            
    @staticmethod
    def postOrderTraversalWithoutRecursion(root: Node) -> list: #return list that contain results
        stack = [root]
        visit = [False]
        res = []
        while len(stack) != 0:
            cur = stack.pop()
            visited = visit.pop()
            if cur != None:
                if visited == True:
                    res.append(cur.val)
                else:
                    stack.append(cur)
                    visit.append(True)
                    stack.append(cur.rightNode)
                    visit.append(False)
                    stack.append(cur.leftNode)
                    visit.append(False)
        return res        
            
print("postOrderTraversalWithRecursion")            
print(Tree.postOrderTraversalWithRecursion(root))
print()
print("postOrderTraversalWithoutRecursion")
print(Tree.postOrderTraversalWithoutRecursion(root))            
