#!/usr/bin/env python3

from math import radians, sin, cos

# 回転移動
def rotate(theta, point):
    x, y = point
    rad = radians(theta)
    return (cos(rad) * x - sin(rad) * y, sin(rad) * x + cos(rad) * y)

# 三角形の面積
def area(A, B, C):
    (A_X, A_Y), (B_X, B_Y), (C_X, C_Y) = A, B, C
    return abs((B_X - A_X)*(C_Y - A_Y) - (B_Y - A_Y)*(C_X - A_X)) / 2


N = int(input())

points = list()

for i in range(N):
    X, Y = map(int, input().split())
    points.append((X, Y))

rotates = [0] * N

Q = int(input())
ans = list()

for _ in range(Q):
    cmd, *query = list(map(int, input().split()))
    if cmd == 1:
        l, r, theta = query
        
        for i, (x, y) in enumerate(points):
            if l <= x**2 + y**2 <= r:
                rotates[i] += theta
        
    if cmd == 2:
        a, b, c = query
        a -= 1; b -= 1; c -= 1
        A = rotate(rotates[a], points[a])
        B = rotate(rotates[b], points[b])
        C = rotate(rotates[c], points[c])
        
        ans.append(str(area(A, B, C)))

print('\n'.join(ans))
