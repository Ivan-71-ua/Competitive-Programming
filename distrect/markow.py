import re
word = input("слово:")
d = []
for _ in range(int(input('кількість перетворень:'))):
    a, b = input().split()
    d.append([a, b])
idx = int(input('введіть номер заключного перетворення:'))
finish = d[idx-1][0]

while True:
    c = 0

    for a, b in d:
        if a == finish and a in word:
            while a in word:
                word = re.sub(a, b, word)
            c = 0
            break
        if a in word:
            while a in word:
                word = re.sub(a, b, word)
                c += 1
            break


    if c == 0:
        break
print(word)