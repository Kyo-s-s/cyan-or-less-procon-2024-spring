#!/usr/bin/env pypy3
import re
import sys
from collections import deque

def main():

    line = re.match(r'^(\d+)$', sys.stdin.readline())
    assert line, 'Does not match with regexp'
    N = int(line.groups()[0])
    assert 2 <= N <= 100000, 'N out of range: %d' % N

    line = re.match(r'(([-\d ]+)+)$', sys.stdin.readline())
    assert line, 'Does not match with regexp'
    Al = list(map(int, line.groups()[0].split()))
    assert len(Al) == N, 'len(A) out of range: %d' % len(Al)
    for a in Al:
        assert -100000 <= a <= 100000, 'A out of range: %d' % a
    
    A = deque(Al)
    
    line = re.match(r'^(\d+)$', sys.stdin.readline())
    assert line, 'Does not match with regexp'
    Q = int(line.groups()[0])
    assert 1 <= Q <= 100000, 'N out of range: %d' % Q

    for _ in range(Q):
        readline = sys.stdin.readline()
        line = re.match(r'^((1|3) (-?\d+)|(2|4))$', readline)
        assert line, 'Does not match with regexp'
        t, *q = list(map(int, readline.split()))

        if t == 1:
            assert -100000 <= q[0] <= 100000, 'x out of range: %d' % q[0]
            A.append(q[0])
        elif t == 2:
            A.pop()
        elif t == 3:
            assert -100000 <= q[0] <= 100000, 'x out of range: %d' % q[0]
            A.appendleft(q[0])
        elif t == 4:
            A.popleft()
        
        assert len(A) >= 2, 'len(A) out of range: %d' % len(A)
         
    assert sys.stdin.read() == '', 'Extra lines'


if __name__ == '__main__':
    main()
