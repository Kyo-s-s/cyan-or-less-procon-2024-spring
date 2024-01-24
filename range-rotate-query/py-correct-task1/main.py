# 三角形の面積
def area(A, B, C):
    (A_X, A_Y), (B_X, B_Y), (C_X, C_Y) = A, B, C
    return abs((B_X - A_X)*(C_Y - A_Y) - (B_Y - A_Y)*(C_X - A_X)) / 2


N = int(input())

points = list()

for i in range(N):
    X, Y = map(int, input().split())
    points.append((X, Y))

Q = int(input())
for _ in range(Q):
    _, *query = list(map(int, input().split()))

    a, b, c = query
    a -= 1; b -= 1; c -= 1
    A = points[a]
    B = points[b]
    C = points[c]
    
    print(area(A, B, C))

