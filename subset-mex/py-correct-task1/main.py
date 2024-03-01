#!/usr/bin/env pypy3

mod = 998244353

N = int(input())
A = list(map(int, input().split()))


ans = 0
for msk in range(1 << N):
    s = [False for _ in range(23)]
    for i in range(N):
        if (msk >> i) & 1:
            s[min(A[i], 22)] = True

    mex = 0
    while s[mex]:
        mex += 1

    ans += mex

print(ans % mod)
