import os, subprocess

def main():
  assert 'PROBLEM' in os.listdir()
  exe = '/'.join(['.', 'cpp-ac-task4', 'a.out'])
  for _in in filter(lambda name: name.endswith('.in'), os.listdir('tests')):
    infile = '/'.join(['.', 'tests', _in])
    outfile = infile.replace('.in', '.diff')
    with open(infile, 'r') as f, open(outfile, 'w') as g:
      subprocess.run(exe, stdin=f, stdout=g, timeout=10)

if __name__ == '__main__':
  main()
