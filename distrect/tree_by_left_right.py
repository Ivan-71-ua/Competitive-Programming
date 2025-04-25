from collections import deque

class TreeNode:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.val = key

def insert_node(parent, child, side):
    if side == 'L':
        parent.left = child
    else:
        parent.right = child

def build_tree(edges):
    nodes = {}
    for edge in edges:
        parent, child = edge[0], edge[1]
        side = 'L' if (parent, child) in L else 'R'
        if parent not in nodes:
            nodes[parent] = TreeNode(parent)
        if child not in nodes:
            nodes[child] = TreeNode(child)
        insert_node(nodes[parent], nodes[child], side)
    return nodes

def find_root(edges):
    children = set(child for _, child in edges)
    for parent, _ in edges:
        if parent not in children:
            return parent
    return None

def height_bfs(root):
    if not root:
        return 0
    queue = deque([root])
    height = 0
    while queue:
        level_length = len(queue)
        for _ in range(level_length):
            node = queue.popleft()
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)
        height += 1
    return height

def preorder(root):
    return root.val + preorder(root.left) + preorder(root.right) if root else ""

def inorder(root):
    return inorder(root.left) + root.val + inorder(root.right) if root else ""

def postorder(root):
    return postorder(root.left) + postorder(root.right) + root.val if root else ""

# Введення даних
L = {('c', 'f'), ('f', 'h'), ('j', 'e'), ('a', 'l'), ('l', 'd')}
R = {('c', 'a'), ('f', 'j'), ('h', 'g'), ('j', 'k'), ('l', 'i'), ('d', 'b')}

edges = list(L) + list(R)

# Побудова дерева
nodes = build_tree(edges)
root_key = find_root(edges)
root = nodes[root_key]

# Перевірка коректності побудови дерева
def print_tree(root, level=0, side="root"):
    if root:
        print(" " * 4 * level + f"{side}: {root.val}")
        print_tree(root.left, level + 1, "L")
        print_tree(root.right, level + 1, "R")

print_tree(root)

# Висота дерева
tree_height = height_bfs(root)
print(f"Висота дерева: {tree_height - 1}")

# Обходи дерева
preorder_traversal = preorder(root)
inorder_traversal = inorder(root)
postorder_traversal = postorder(root)

print(f"Прямий обхід: {preorder_traversal}")
print(f"Внутрішній обхід: {inorder_traversal}")
print(f"Зворотний обхід: {postorder_traversal}")
