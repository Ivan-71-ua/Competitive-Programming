# занести уввід у форматі:
# b1 m1
# b2 m2
# ...
# bn mn

import sys


def rev(x, m):
    for i in range(1, m):
        if (x * i) % m == 1:
            return i

    return -1


b, m = [], []
MOD = 1
for _ in range(int(input('n:'))):
    x, y = map(int, input().split())
    b.append(x)
    m.append(y)
    MOD *= y

M = []
for i in m:
    M.append(MOD // i)

Mch = []
for i in range(len(M)):
    Mch.append(rev(M[i], m[i]))
    if Mch == -1:
        print('Ймовірно відпвіді немає')
        exit(0)

x0 = 0
for i in range(len(m)):
    x0 += b[i] * M[i] * Mch[i]

print("answer = {0}(mod {1})".format(x0 % MOD, MOD))