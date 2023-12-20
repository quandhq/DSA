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
    def postOrderTraversalWithRecursion(root: Node) -> None:    #return list that contain results
        if root != None:
            Tree.postOrderTraversalWithRecursion(root.leftNode)
            print(root.val, end=" ")
            Tree.postOrderTraversalWithRecursion(root.rightNode)
            
Tree.postOrderTraversalWithRecursion(root)
            
