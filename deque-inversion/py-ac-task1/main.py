#!/usr/bin/env pypy3

def count_inverse(A):
  cnt = 0
  for i in range(len(A)):
    for j in range(i+1, len(A)):
      if A[i] > A[j]:
        cnt += 1
  return cnt

def main():
  N = int(input())
  A = list(map(int, input().split()))
  assert N <= 100

  Q = int(input())
  assert Q <= 100
  for _ in range(Q):
    T, X = map(int, input().split())
    assert T == 2 or T == 4
    if T == 2:
      A.append(X)
    if T == 4:
      A.pop()
    print(count_inverse(A))

main()
