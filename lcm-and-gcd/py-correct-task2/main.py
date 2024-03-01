#!/usr/bin/env pypy3

import math

mod = 998244353

N = int(input())
A = list(map(int, input().split()))

for i in range(N):
    for j in range(i + 1, N):
        g = math.gcd(A[i], A[j])
        l = math.lcm(A[i], A[j])
        A[i] = g
        A[j] = l

ans = [a % mod for a in A]
print(*ans)
