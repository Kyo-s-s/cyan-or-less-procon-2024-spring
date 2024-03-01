from dataclasses import dataclass

@dataclass
class Constraints:
  N_MIN: int = 2
  N_MAX: int = 10**5
  Q_MIN: int = 1
  Q_MAX: int = 10**5
  T_LIST: 'tuple[str]' = ('push_front', 'push_back', 'pop_front', 'pop_back')
  X_MIN: int = -10**5
  X_MAX: int = 10**5

@dataclass
class Task1(Constraints):
  N_MAX: int = 100
  Q_MAX: int = 100
  T_LIST: 'tuple[str]' = ('push_back', 'pop_back')

@dataclass
class Task2(Constraints):
  N_MAX: int = 100
  Q_MAX: int = 100

@dataclass
class Task3(Constraints):
  N_MIN: int = 100
  N_MAX: int = 5000
  Q_MAX: int = 100

@dataclass
class Task4(Constraints):
  N_MIN: int = 5000
  Q_MIN: int = 100

def fprintATX(fptr, A: 'list[int]', T: 'list[str]', X: 'list[int]'):
  print(len(A), file=fptr)
  print(*A, file=fptr)
  assert len(T) == len(X)
  print(len(T), file=fptr)
  for t, x in zip(T, X):
    print(t, x, file=fptr)

if __name__ == '__main__':
  # test run
  print(Constraints())
  print(Task1())
  print(Task2())
  print(Task3())
  print(Task4())
