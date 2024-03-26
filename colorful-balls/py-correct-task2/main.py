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
        assert 1 <= x <= 10**9
        assert 1 <= c <= 10**9
        clr.append(c)
        cnt.append(x)

    if T == 2:
        x = q[0]
        while x > 0:
            c = min(cnt[-1], x)
            cnt[-1] -= c
            x -= c
            if cnt[-1] == 0:
                clr.pop()
                cnt.pop()
        
    if T == 3:
        x = q[0]
        idx = len(cnt) - 1
        while x > 0:
            c = min(cnt[idx], x)
            x -= c
            idx -= 1

        print(clr[idx + 1])

