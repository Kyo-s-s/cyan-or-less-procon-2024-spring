from collections import deque
from random import seed, randint, choice, sample
from writertools import *

def make_random(name: str, cons: Constraints):
  with open(name+'.in', 'w') as f:
    N = cons.N_MAX
    A = [randint(cons.X_MIN, cons.X_MAX) for _ in range(N)]
    Q = cons.Q_MAX
    _T_PUSH = tuple(filter(type_is_push, cons.T_LIST))
    T = [choice(_T_PUSH) for _ in range(Q)]
    X = [randint(cons.X_MIN, cons.X_MAX) for _ in range(Q)]
    fprintATX(f, A, T, X)

def make_sorted(name: str, cons: Constraints):
  with open(name+'.in', 'w') as f:
    N = cons.N_MAX
    Q = cons.Q_MAX
    _A = sample(range(cons.X_MIN, cons.X_MAX+1), N+Q)
    _A.sort(reverse=True)
    _A = deque(_A)
    _T_PUSH = tuple(filter(type_is_push, cons.T_LIST))
    T = [choice(_T_PUSH) for _ in range(Q)]
    X = [_A.popleft() if type_is_front(t) else _A.pop() for t in reversed(T)]
    X.reverse()
    fprintATX(f, list(_A), T, X)

def main():
  seed('水以下コンテスト')
  for i, c in enumerate([Task1, Task2, Task3, Task4], 1):
    make_random(f'task{i}_random_max', c)
    make_sorted(f'task{i}_sorted_max', c)
