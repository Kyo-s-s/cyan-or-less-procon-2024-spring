#!/usr/bin/env pypy3

mod = 998244353

N, K = map(int, input().split())

if N == 1:
    print(K)
    exit()

if N == 2:
    print(K * (K - 1) % mod)
    exit()

inc = [0 for _ in range(K)]
dec = [0 for _ in range(K)]
for a in range(K):
    for b in range(K):
        if a > b:
            dec[b] += 1
        if a < b:
            inc[b] += 1

for _ in range(2, N):
    ninc = [0 for _ in range(K)]
    ndec = [0 for _ in range(K)]

    for a in range(K):
        for b in range(K):
            if a > b:
                ndec[b] += inc[a]
            if a < b:
                ninc[b] += dec[a]

    inc = [(x % mod + mod) % mod for x in ninc]
    dec = [(x % mod + mod) % mod for x in ndec]

ans = sum(inc) + sum(dec)
print(ans % mod)
