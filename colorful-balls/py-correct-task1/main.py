#!/usr/bin/env pypy3

Q = int(input())

assert 1 <= Q <= 5000

clr = []
cnt = []


for _ in range(Q):

    T, *q = list(map(int, input().split()))

    if T == 1:
        x = q[0]
        c = q[1]
        assert x == 1
        assert 1 <= c <= 10**9
        clr.append(c)
        cnt.append(x)

    if T == 2:
        x = q[0]
        assert x == 1
        clr.pop()
        cnt.pop()

    if T == 3:
        x = q[0]
        print(clr[len(clr) - x])
