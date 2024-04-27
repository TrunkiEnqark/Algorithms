class Node: 
    def __init__(self, key):
        self.key = key
        self.parent = self.child = self.left = self.right = None
        self.degree = 0
        self.mark = False