import os, subprocess

def main():
  exe = '../cpp-ac-task4/a.out'
  for I in filter(lambda name: name.endswith('.in'), os.listdir()):
    O = I.replace('.in', '.diff')
    with open(I, 'r') as fi, open(O, 'w') as fo:
      subprocess.run(exe, stdin=fi, stdout=fo, timeout=10)

if __name__ == '__main__':
  main()
