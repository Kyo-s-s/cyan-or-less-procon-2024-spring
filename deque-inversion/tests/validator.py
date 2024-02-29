#!/usr/bin/env python3
from collections import deque

def main():
  N = int(input())
  A = deque(map(int, input().split()))
  assert 2 <= N <= 10**5
  assert all(-10**5 <= a <= 10**5 for a in A)
  Q = int(input())
  assert 1 <= Q <= 10**5
  for _ in range(Q):
    T, X = input().split()
    X = int(X)
    # assert T in ['push_front', 'push_back', 'pop_front', 'pop_back']
    assert T in ['1', '2', '3', '4']
    assert -10**5 <= X <= 10**5
    if 'pop' in T:
      assert X == 0
    if T == '1':
      A.appendleft(X)
    if T == '2':
      A.append(X)
    if T == '3':
      A.popleft()
    if T == '4':
      A.pop()
    assert len(A) >= 2

if __name__ == '__main__':
  main()
