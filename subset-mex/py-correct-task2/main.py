#!/usr/bin/env python3

mod = 998244353

N = int(input())
A = list(map(int, input().split()))


cnt = [0 for _ in range(1010)]
for a in A:
    cnt[a] += 1

ans = 0
for mex in range(1005):
    c = 1
    for i in range(mex):
        c *= pow(2, cnt[i], mod) - 1
        c %= mod
    for i in range(mex + 1, 1010):
        c *= pow(2, cnt[i], mod)
        c %= mod
    
    ans += mex * c
    ans %= mod

print(ans)
