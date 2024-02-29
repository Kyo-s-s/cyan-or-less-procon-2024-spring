#!/usr/bin/env python3

mod = 998244353

N = int(input())
A = list(map(int, input().split()))

cnt = [0 for _ in range(202020)]

for a in A:
    cnt[a] += 1

ones = 1
big = N
ans = 0

for mex in range(202020):
    big -= cnt[mex]
    ans += mex * ones * pow(2, big, mod)
    ones *= pow(2, cnt[mex], mod) - 1

    ans %= mod
    ones %= mod

print(ans % mod)
