#!/usr/bin/env python3

import re
import sys

def main():

    line = re.match(r'(\d+)$', sys.stdin.readline())
    assert line, 'Does not match with regexp'
    N = int(line.groups()[0])
    assert 2 <= N <= 100000, 'N out of range: %d' % N

    line = re.match(r'(([\d ]+)+)$', sys.stdin.readline())
    assert line, 'Does not match with regexp'
    A = list(map(int, line.groups()[0].split()))
    assert len(A) == N, 'len(A) out of range: %d' % len(A)
    for a in A:
        assert 1 <= a <= 200000, 'A out of range: %d' % a

    assert sys.stdin.read() == '', 'Extra lines'

if __name__ == '__main__':
    main()
