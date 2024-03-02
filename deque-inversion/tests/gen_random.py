from random import seed, randint, choice
from writertools import *

def _make_query(n: int, q: int, cons: Constraints):
  T = [choice(cons.T_LIST) for _ in range(q)]
  X = [randint(cons.X_MIN, cons.X_MAX) for _ in range(q)]
  for i in range(q):
    if n == 2 and type_is_pop(T[i]):
      T[i] = pop_to_push(T[i])
    if type_is_push(T[i]):
      n += 1
    if type_is_pop(T[i]):
      X[i] = 0
      n -= 1
  if randint(1, 3) == 3:
    _I = list(filter(lambda i : type_is_push(T[i]), range(q)))
    for _ in range(3):
      X[choice(_I)] = cons.X_MIN
    for _ in range(3):
      X[choice(_I)] = cons.X_MAX
  return T, X

def make(name: str, cons: Constraints):
  with open(name, 'w') as f:
    N = randint(cons.N_MIN, cons.N_MAX)
    A = [randint(cons.X_MIN, cons.X_MAX) for _ in range(N)]
    Q = randint(cons.Q_MIN, cons.Q_MAX)
    T, X = _make_query(N, Q, cons)
    fprintATX(f, A, T, X)

def make_n(task_class: str, n: int, cons: Constraints):
  for i in range(n):
    make(f'{task_class}_{i}.in', cons)

def main():
  seed(0)
  make_n('task1_random', 6, Task1())
  make_n('task2_random', 6, Task2())
  make_n('task3_random', 6, Task3())
  make_n('task4_random', 6, Task4())
