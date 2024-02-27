#!/usr/bin/env python3
from random import seed, randint, choice

def make_A(n: int):
  return [randint(-10**5, 10**5) for _ in range(n)]

def make_query(n: int, q: int, t: 'list[str]' = None):
  if t is None:
    t = ['push_front', 'push_back', 'pop_front', 'pop_back']
  push_only = list(filter(lambda s: 'push' in s, t))
  T = []
  X = []
  for _ in range(q):
    if n == 2:
      T.append(choice(push_only))
    else:
      T.append(choice(t))
    if 'push' in T[-1]:
      n += 1
      X.append(randint(-10**5, 10**5))
    else:
      n -= 1
      X.append(0)
  return T, X

def print_data(N, A, Q, T, X, f):
  print(N, file=f)
  print(*A, file=f)
  print(Q, file=f)
  for t, x in zip(T, X):
    print(t, x, file=f)

def task1():
  for i in range(10):
    with open(f'./task1_random{i}.in', 'w') as f:
      N = randint(2, 100)
      Q = randint(1, 100)
      T, X = make_query(N, Q, ['push_back', 'pop_back'])
      print_data(N, make_A(N), Q, T, X, f)

def task2():
  for i in range(10):
    with open(f'./task2_random{i}.in', 'w') as f:
      N = randint(2, 100)
      Q = randint(1, 100)
      T, X = make_query(N, Q)
      print_data(N, make_A(N), Q, T, X, f)

def task3():
  for i in range(7):
    with open(f'./task3_random{i}.in', 'w') as f:
      N = randint(1000, 5000)
      Q = randint(1, 100)
      T, X = make_query(N, Q)
      print_data(N, make_A(N), Q, T, X, f)
  for i in range(3):
    with open(f'./task3_max{i}.in', 'w') as f:
      N = 5000
      Q = 100
      T, X = make_query(N, Q)
      print_data(N, make_A(N), Q, T, X, f)

def task4():
  for i in range(7):
    with open(f'task4_random{i}.in', 'w') as f:
      N = randint(10000, 100000)
      Q = randint(100, 100000)
      T, X = make_query(N, Q)
      print_data(N, make_A(N), Q, T, X, f)
  for i in range(3):
    with open(f'task4_max{i}.in', 'w') as f:
      N = 10**5
      Q = 10**5
      T, X = make_query(N, Q)
      print_data(N, make_A(N), Q, T, X, f)

if __name__ == '__main__':
  seed(0)
  task1()
  task2()
  task3()
  task4()
