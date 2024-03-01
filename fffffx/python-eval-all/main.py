#!/usr/bin/env pypy3

import re

K = int(input())
S = '(' + re.sub(r'(x|\d+)\^(\d+)', r'pow(\1,\2,998)', input()) + ')%998'

m = 62
doubling = [[0]*998 for _ in range(m)]

for x in range(998):
    doubling[0][x] = eval(S)

for i in range(m-1):
    for x in range(998):
        doubling[i+1][x] = doubling[i][doubling[i][x]]

x = 1
for i in range(m):
    if (K >> i) & 1 == 1: x = doubling[i][x]

print(x)
