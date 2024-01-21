#!/usr/bin/python3

import re
import sys

def main():

    line = re.match(r'(\d+) (\d+)$', sys.stdin.readline())
    assert line, 'Does not match with regexp'
    N, K = map(int, line.groups())
    assert 4 <= N <= 5000, 'N out of range: %d' % N
    assert 1 <= K <= 1000000, 'K out of range: %d' % K

    for _ in range(K):
        line = re.match(r'(\d+) (\d+) (\d+) (\d+)$', sys.stdin.readline())
        assert line, 'Does not match with regexp'
        t, a, b, c = map(int, line.groups())
        assert t in [1, 2], 't out of range: %d' % t
        assert 1 <= a < b < c <= N, 'a, b, c out of range: %d, %d, %d' % (a, b, c)

    assert sys.stdin.read() == '', 'Extra lines'

if __name__ == '__main__':
    main()
