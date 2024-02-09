#!/usr/bin/env python3
from collections import deque

def main():
  N = int(input())
  A = deque(map(int, input().split()))
  assert 2 <= N <= 10**5
  assert all(-10**6 <= a <= 10**6 for a in A)
  Q = int(input())
  assert 1 <= Q <= 10**5
  for _ in range(Q):
    T, X = input().split()
    X = int(X)
    assert T in ['push_front', 'push_back', 'pop_front', 'pop_back']
    assert -10**6 <= X <= 10**6
    if 'pop' in T:
      assert X == 0
    if T == 'push_front':
      A.appendleft(X)
    if T == 'push_back':
      A.append(X)
    if T == 'pop_front':
      A.popleft()
    if T == 'pop_back':
      A.pop()
    assert len(A) >= 2

if __name__ == '__main__':
  main()
