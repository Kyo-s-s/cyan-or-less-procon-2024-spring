#!/usr/bin/python3

import re
import sys

def main():
    line = re.match(r'(\d+) (\d+)$', sys.stdin.readline())
    assert line, 'Does not match with regexp'
    N, M = map(int, line.groups())
    assert 2 <= N <= 100000, 'N out of range: %d' % N
    assert 1 <= M <= 100000, 'M out of range: %d' % M

    line = re.match(r'(([\d ]+)+)$', sys.stdin.readline())
    assert line, 'Does not match with regexp'
    C = list(map(int, line.groups()[0].split()))
    assert len(C) == M, 'len(C) out of range: %d' % len(C)
    for c in C:
        assert 2 <= c, 'C out of range: %d' % c
    assert sum(C) <= 100000, 'sum(C) out of range: %d' % sum(C)
    

    line = re.match(r'(([\d ]+)+)$', sys.stdin.readline())
    assert line, 'Does not match with regexp'
    D = list(map(int, line.groups()[0].split()))
    assert len(D) == M, 'len(D) out of range: %d' % len(D)
    for d in D:
        assert 1 <= d <= 1000000000, 'D out of range: %d' % d

    for i in range(M):
        line = re.match(r'(([\d ]+)+)$', sys.stdin.readline())
        assert line, 'Does not match with regexp'
        A = list(map(int, line.groups()[0].split()))
        assert len(A) == C[i], 'len(A) out of range: %d' % len(A)
        for a in A:
            assert 1 <= a <= N, 'A out of range: %d' % a
        assert len(set(A)) == len(A), 'A is not unique: %s' % A




if __name__ == '__main__':
    main()
