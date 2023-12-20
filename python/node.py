class Node:
    val: int = None
    leftNode = None
    rightNode = None

    def __init__(self) -> None:
        pass

    def __init__(self, val) -> None:
        self.val = val
        
    def __init__(self, val: int, leftNode, rightNode) -> None:
        self.val = val
        self.leftNode = leftNode
        self.rightNode = rightNode
     
    