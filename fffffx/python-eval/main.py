#!/usr/bin/env pypy3

K = int(input())
S = '(' + input().replace('^', '**') + ')%998'

x = 1
for k in range(0, K):
    x = eval(S)

print(x)

