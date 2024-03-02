#!/usr/bin/env pypy3

N, K = map(int, input().split())

ans = 0

for s in range(pow(K, N)):
    a = []
    for _ in range(N):
        a.append(s % K)
        s //= K

    diff = []    
    for i in range(1, N):
        diff.append(a[i] - a[i - 1])

    difff = []
    for i in range(1, N - 1):
        difff.append(diff[i] * diff[i - 1])


    if all([x != 0 for x in diff]) and all([x < 0 for x in difff]):
        ans += 1

print(ans)
