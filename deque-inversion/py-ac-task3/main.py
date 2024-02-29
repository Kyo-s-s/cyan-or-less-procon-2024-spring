#!/usr/bin/env python3
from collections import deque

class fenwick_tree:
  def __init__(self, n):
    self.__n = n
    self.__dat = [0] * n
  def __sum(self, r):
    s = 0
    while r > 0:
      s += self.__dat[r-1]
      r -= r & -r
    return s
  def add(self, i, x):
    # assert 0 <= i < self.__n
    i += 1
    while i <= self.__n:
      self.__dat[i-1] += x
      i += i & -i
  def sum(self, l, r):
    # assert 0 <= l <= r <= self.__n
    return self.__sum(r) - self.__sum(l)

def count_inverse(A):
  INF = 2 * 10**5 + 1
  OFFSET = 10**5
  cnt = fenwick_tree(INF)
  answer = 0
  for a in A:
    answer += cnt.sum(a+1 + OFFSET, INF)
    cnt.add(a + OFFSET, 1)
  return answer

def main():
  N = int(input())
  A = deque(map(int, input().split()))
  assert N <= 5000

  Q = int(input())
  assert Q <= 100
  for T, X in [map(int, input().split()) for _ in range(Q)]:

    if T == 1:
      A.appendleft(X)
    if T == 2:
      A.append(X)
    if T == 3:
      A.popleft()
    if T == 4:
      A.pop()

    print(count_inverse(A))

main()
