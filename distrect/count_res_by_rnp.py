tokens = input().split()
stack = []
for c in tokens:
    if c == "+":
        stack.append(stack.pop() + stack.pop())
    elif c == "-":
        a, b = stack.pop(), stack.pop()
        stack.append(b - a)
    elif c == "*":
        stack.append(stack.pop() * stack.pop())
    elif c == "/":
        a, b = stack.pop(), stack.pop()
        stack.append(int(float(b) / a))
    elif c == 'min':
        a, b = stack.pop(), stack.pop()
        stack.append(min(a, b))
    elif c == 'max':
        a, b = stack.pop(), stack.pop()
        stack.append(max(a, b))
    elif c == '^':
        a, b = stack.pop(), stack.pop()
        stack.append(b**a)
    elif c == '%':
        a, b = stack.pop(), stack.pop()
        stack.append(b % a)
    else:
        stack.append(int(c))
print(stack[0])