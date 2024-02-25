#!/usr/bin/env python3

X = int(input())
S = list(input())

while len(S) < X:
    S.append('`')

dp = [0 for _ in range(10)]
dp[0] = 1

ans = 0

for x in range(X):
    pd = [0 for _ in range(10)]
    for ij in range(10):
        i = ij // 5
        j = ij % 5
        for c in range(ord('a'), ord('z') + 1):
            ni = 0 if i == 0 and chr(c) == S[x] else (-1 if i == 0 and chr(c) > S[x] else 1)
            if ni == -1:
                continue
            nj = 4 if j == 4 else (1 if chr(c) == 'c' else (2 if j == 1 and chr(c) == 'y' else (3 if j == 2 and chr(c) == 'a' else (4 if j == 3 and chr(c) == 'n' else 0))))
            pd[ni * 5 + nj] += dp[i * 5 + j]

    dp = pd
    for i in range(10):
        dp[i] %= 998244353

    ans += dp[4] + dp[9]
    ans %= 998244353

print(ans)
