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
    assert 0 <= i < self.__n
    i += 1
    while i <= self.__n:
      self.__dat[i-1] += x
      i += i & -i
  def sum(self, l, r):
    assert 0 <= l <= r <= self.__n
    return self.__sum(r) - self.__sum(l)

def main():
  N = int(input())
  A = deque(map(int, input().split()))

  INF = 2 * 10**5 + 1
  OFFSET = 10**5
  answer = 0
  cnt = fenwick_tree(INF)
  for a in A:
    answer += cnt.sum(a+1 + OFFSET, INF)
    cnt.add(a + OFFSET, 1)

  Q = int(input())
  for _ in range(Q):
    T, X = map(int, input().split())

    if T == 1:
      answer += cnt.sum(0, X + OFFSET)
      cnt.add(X + OFFSET, 1)
      A.appendleft(X)
    if T == 2:
      answer += cnt.sum(X+1 + OFFSET, INF)
      cnt.add(X + OFFSET, 1)
      A.append(X)
    if T == 3:
      answer -= cnt.sum(0, A[0] + OFFSET)
      cnt.add(A[0] + OFFSET, -1)
      A.popleft()
    if T == 4:
      answer -= cnt.sum(A[-1]+1 + OFFSET, INF)
      cnt.add(A[-1] + OFFSET, -1)
      A.pop()

    print(answer)

main()
