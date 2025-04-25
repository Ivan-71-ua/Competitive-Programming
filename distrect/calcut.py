class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

def infix(node):
    if node is None:
        return ""
    left = infix(node.left)
    right = infix(node.right)
    return f"({left} {node.value} {right})" if left and right else f"{node.value}"

def prefix(node):
    if node is None:
        return ""
    left = prefix(node.left)
    right = prefix(node.right)
    return f"{node.value} {left} {right}".strip()

def postfix(node):
    if node is None:
        return ""
    left = postfix(node.left)
    right = postfix(node.right)
    return f"{left} {right} {node.value}".strip()

def parse_expression(expression):
    import re
    precedence = {'+': 1, '-': 1, '*': 2, '/': 2, '^': 3, '%': 2, 'min': 4, 'max': 4}
    def get_precedence(op):
        return precedence.get(op, 0)
    
    def shunting_yard(expression):
        output = []
        operators = []
        tokens = re.findall(r'\d+|[a-zA-Z]+|\S', expression)
        
        for token in tokens:
            if token.isnumeric() or re.match(r'[a-zA-Z]+', token):
                output.append(token)
            elif token == '(':
                operators.append(token)
            elif token == ')':
                while operators and operators[-1] != '(':
                    output.append(operators.pop())
                operators.pop()
            else:
                while (operators and operators[-1] != '(' and 
                       get_precedence(operators[-1]) >= get_precedence(token)):
                    output.append(operators.pop())
                operators.append(token)
        
        while operators:
            output.append(operators.pop())
        
        return output
    
    def build_tree(postfix):
        stack = []
        for token in postfix:
            node = Node(token)
            if token in precedence:
                node.right = stack.pop()
                node.left = stack.pop()
            stack.append(node)
        return stack[0]
    
    postfix_expression = shunting_yard(expression)
    tree = build_tree(postfix_expression)
    return tree

# Приклад використання для даних виразів:
expressions = [
    "(b % (min(a, b / c) - a)) % max(min(8, b % 6), b % c * a + max)",
    "2 8 3 - 6 3 / max 8 9 + *",
    "(8 * (b - max(a, 7)) + b) % max((5 % c)^b, a/min(b, 3))"
]

for expr in expressions:
    tree = parse_expression(expr)
    print("Infix notation: ", infix(tree))
    print("Prefix notation: ", prefix(tree))
    print("Postfix notation: ", postfix(tree))
