#!/usr/bin/env pypy3
import heapq

N, M = map(int, input().split())
C = list(map(int, input().split()))
D = list(map(int, input().split()))

G = [[] for _ in range(N)]

for i in range(M):
    A = list(map(lambda x: int(x) - 1, input().split()))
    for a in A:
        for b in A:
            if a != b:
                G[a].append((b, D[i]))


dist = [10**18 for _ in range(N)]
dist[0] = 0

pq = [(0, 0)]

while pq:
    d, v = heapq.heappop(pq)
    if dist[v] < d:
        continue

    for u, c in G[v]:
        if dist[u] > dist[v] + c:
            dist[u] = dist[v] + c
            heapq.heappush(pq, (dist[u], u))

for i in range(1, N):
    print(dist[i] if dist[i] < 10**18 else -1)
