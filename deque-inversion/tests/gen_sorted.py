from copy import deepcopy
from collections import deque
from random import seed, randint, choice
from writertools import *

def _make_query(a: 'list[int]', rev: int, q: int, cons: Constraints):
  _A = deque(a)
  T = [choice(cons.T_LIST) for _ in range(q)]
  X: 'list[int]' = []
  for i in range(q):
    if len(_A) == 2 and T[i].startswith('pop'):
      T[i] = T[i].replace('pop', 'push')
    match T[i]:
      case 'push_front':
        X.append(randint(_A[0], cons.X_MAX) if rev else randint(cons.X_MIN, _A[0]))
        _A.appendleft(X[-1])
      case 'push_back':
        X.append(randint(cons.X_MIN, _A[-1]) if rev else randint(_A[-1], cons.X_MAX))
        _A.append(X[-1])
      case 'pop_front':
        X.append(0)
        _A.popleft()
      case 'pop_back':
        X.append(0)
        _A.pop()
  return T, X

def make(name: str, cons: Constraints, rev: bool, nq_max = False):
  with open(name, 'w') as f:
    N = randint(cons.N_MAX-10, cons.N_MAX) if nq_max else randint(cons.N_MIN, cons.N_MAX)
    A = sorted((randint(cons.X_MIN * 85 // 100, cons.X_MAX * 85 // 100) for _ in range(N)), reverse=rev)
    Q = randint(cons.Q_MAX-10, cons.Q_MAX) if nq_max else randint(cons.Q_MIN, cons.Q_MAX)
    T, X = _make_query(deepcopy(A), rev, Q, cons)
    fprintATX(f, A, T, X)

def make_n(task_class: str, n: int, cons: Constraints, nq_max = False):
  for i in range(n):
    make(f'{task_class}_{i}.in', cons, i%2, nq_max)

def main():
  seed(998244353)
  make_n('task1_sorted', 2, Task1())
  make_n('task2_sorted', 2, Task2())
  make_n('task3_sorted', 2, Task3())
  make('task3_sorted_max.in', Task3(), True, True)
  make_n('task4_sorted', 2, Task4())
  make('task4_sorted_max.in', Task4(), True, True)
