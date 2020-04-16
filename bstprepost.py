class node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


def insert(root, temp_node):
    if root is None:
        root = temp_node
    elif root.data > temp_node.data:
        if root.left is None:
            root.left = temp_node
        else:
            insert(root.left, temp_node)
    else:
        if root.right is None:
            root.right = temp_node
        else:
            insert(root.right, temp_node)


def inorder(root):
    if root:
        inorder(root.left)
        print(root.data, end=" ")
        inorder(root.right)


def preorder(root):
    if root:
        print(root.data, end=" ")
        preorder(root.left)
        preorder(root.right)


def postorder(root):
    if root:
        postorder(root.left)
        postorder(root.right)
        print(root.data, end=" ")


list_arr = []
n = int(input("enter the no of nodes"))
print("enter the key values for nodes")
for i in range(n):
    x = int(input())
    if(i == 0):
        root = node(x)
    else:
        insert(root, node(x))
print("in_order traversal :", end=" ")
inorder(root)
print()
print("pre_order traversal :", end=" ")
preorder(root)
print()
print("post_order traversal :", end=" ")
postorder(root)
