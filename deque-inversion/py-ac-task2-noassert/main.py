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

  Q = int(input())
  for _ in range(Q):
    T, X = input().split()
    X = int(X)

    if T == 'push_front':
      A.insert(0, X)
    if T == 'push_back':
      A.append(X)
    if T == 'pop_front':
      A.pop(0)
    if T == 'pop_back':
      A.pop()

    print(count_inverse(A))

main()
