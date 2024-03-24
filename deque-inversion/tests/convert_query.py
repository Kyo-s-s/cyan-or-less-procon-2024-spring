import os, subprocess

exe = './a.out'

def convert(I):
    memo = I.replace('.in', '.memo')
    with open(I, 'r') as fi, open(memo, 'w') as fo:
        subprocess.run(exe, stdin=fi, stdout=fo, timeout=10)

    os.remove(I)
    os.rename(memo, I)

for I in filter(lambda name: name.endswith('.in'), os.listdir()):
    convert(I)


