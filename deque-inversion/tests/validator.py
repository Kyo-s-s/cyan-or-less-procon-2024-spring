#!/usr/bin/env pypy3
from collections import deque
from writertools import *

def main():
  N = int(input())
  A = deque(map(int, input().split()))
  assert Constraints.N_MIN <= N <= Constraints.N_MAX
  assert all(Constraints.X_MIN <= a <= Constraints.X_MAX for a in A)
  Q = int(input())
  assert Constraints.Q_MIN <= Q <= Constraints.Q_MAX
  for _ in range(Q):
    T, X = input().split()
    X = int(X)
    assert T in Constraints.T_LIST
    assert Constraints.X_MIN <= X <= Constraints.X_MAX
    if type_is_pop(T):
      assert X == 0
    if type_is_push(T) and type_is_front(T):
      A.appendleft(X)
    if type_is_push(T) and type_is_back(T):
      A.append(X)
    if type_is_pop(T) and type_is_front(T):
      A.popleft()
    if type_is_pop(T) and type_is_back(T):
      A.pop()
    assert len(A) >= 2

if __name__ == '__main__':
  main()
