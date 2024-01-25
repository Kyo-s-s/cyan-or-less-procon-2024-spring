#!/usr/bin/python3

from math import pi, sin, cos
from bisect import bisect_left, bisect_right

# 座圧
def shrink(arr):
    shrinked_set = sorted(set(arr))
    shrinked_dict = {s: i for i, s in enumerate(shrinked_set)}

    shrinked = [shrinked_dict[a] for a in arr]
    return shrinked

# 双対BIT
class Dual_Fenwick_Tree:
    def __init__(self, n):
        self._n = n + 1
        self.data = [0] * (n + 1)

    # l 以上 r 未満の区間に x を加算する
    def prod(self, l, r, x):
        self._add(l, x)
        self._add(r, -x)

    # 添え字 p の値を返す
    def get(self, p):
        return self._sum(p) - self._sum(0)

    def _add(self, p, x):
        while p <= self._n:
            self.data[p - 1] += x
            p += p & -p

    def _sum(self, r):
        s = 0
        while r > 0:
            s += self.data[r - 1]
            r -= r & -r
        return s

# 回転移動
def rotate(theta, point):
    x, y = point
    rad = (theta % 360) * pi / 180
    return (cos(rad) * x - sin(rad) * y, sin(rad) * x + cos(rad) * y)

# 三角形の面積
def area(A, B, C):
    (A_X, A_Y), (B_X, B_Y), (C_X, C_Y) = A, B, C
    return abs((B_X - A_X)*(C_Y - A_Y) - (B_Y - A_Y)*(C_X - A_X)) / 2


N = int(input())

points = list()
distances = list()

for i in range(N):
    X, Y = map(int, input().split())
    points.append((X, Y))
    distances.append(X**2 + Y**2)

shrinked_distances = shrink(distances)
distinct_distances = sorted(set(distances))
dual_bit = Dual_Fenwick_Tree(len(distinct_distances))

Q = int(input())
for _ in range(Q):
    cmd, *query = list(map(int, input().split()))
    match cmd:
        case 1:
            l, r, theta = query
            
            begin = bisect_left(distinct_distances, l)
            end = bisect_right(distinct_distances, r)
            
            dual_bit.prod(begin, end, theta)
        
        case 2:
            a, b, c = query
            a -= 1; b -= 1; c -= 1
            A = rotate(dual_bit.get(shrinked_distances[a]), points[a])
            B = rotate(dual_bit.get(shrinked_distances[b]), points[b])
            C = rotate(dual_bit.get(shrinked_distances[c]), points[c])
            
            print(area(A, B, C))

