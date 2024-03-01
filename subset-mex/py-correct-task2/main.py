#!/usr/bin/env pypy3

mod = 998244353

N = int(input())
A = list(map(int, input().split()))


cnt = [0 for _ in range(1002)]
for a in A:
    cnt[a] += 1

ans = 0
for mex in range(1002):
    c = 1
    for i in range(mex):
        c *= pow(2, cnt[i], mod) - 1
        if c >= mod:
            c %= mod
    cs = 0
    for i in range(mex + 1, 1002):
        cs += cnt[i]
    
    c *= pow(2, cs, mod)
    if c >= mod:
        c %= mod
    
    ans += mex * c
    if ans >= mod:
        ans %= mod

print(ans)
