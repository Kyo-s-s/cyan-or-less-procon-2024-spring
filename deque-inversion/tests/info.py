import os
from collections import deque, Counter
from writertools import *

def describe(file):
  with open(file, 'r') as I:
    N = int(I.readline())
    A = deque(map(int, I.readline().split()))
    minmax = [min(A), max(A)]
    cnt = Counter()
    Q = int(I.readline())
    for _ in range(Q):
      T, X = I.readline().split()
      X = int(X)
      cnt[T] += 1
      minmax[0] = min(minmax[0], X)
      minmax[1] = max(minmax[1], X)
  print(file)
  print(f'  {N=} {Q=}')
  print(f'  {minmax=}')
  print('  ', cnt, sep='')

def main():
  for f in sorted(filter(lambda s : s.endswith('.in'), os.listdir())):
    describe(f)

if __name__ == '__main__':
  main()
