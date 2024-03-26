#!/usr/bin/env pypy3
import bisect 

Q = int(input())

clr = list()
cnt = list()
cum = [0]

assert 1 <= Q <= 2 * 10**5

for _ in range(Q):
    T, *q = list(map(int, input().split()))

    if T == 1:
        x = q[0]
        c = q[1]
        assert 1 <= x <= 10**9
        assert 1 <= c <= 10**9
        clr.append(c)
        cnt.append(x)
        cum.append(cum[-1] + x)

    if T == 2:
        x = q[0]
        while x > 0:
            assert len(cum) > 0
            c = min(cnt[-1], x)
            cnt[-1] -= c
            cum[-1] -= c
            x -= c
            if cnt[-1] == 0:
                clr.pop()
                cnt.pop()
                cum.pop()
        
    if T == 3:
        x = q[0]
        idx = bisect.bisect_left(cum, cum[-1] - x + 1)
        print(clr[idx - 1])
