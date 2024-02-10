#!/usr/bin/env python3

import re
import sys

def main():

    line = re.match(r'^(\d+)$', sys.stdin.readline())
    assert line, 'Does not match with regexp'
    N = int(line.groups()[0])
    assert 3 <= N <= 100000, 'N out of range: %d' % N

    for _ in range(N):
        line = re.match(r'^(-?\d+) (-?\d+)$', sys.stdin.readline())
        assert line, 'Does not match with regexp'
        X, Y = map(int, line.groups())
        assert -100000 <= X <= 100000, 'X out of range: %d' % X
        assert -100000 <= Y <= 100000, 'Y out of range: %d' % Y
    
    line = re.match(r'^(\d+)$', sys.stdin.readline())
    assert line, 'Does not match with regexp'
    Q = int(line.groups()[0])
    assert 1 <= Q <= 50000, 'N out of range: %d' % Q

    for _ in range(Q):
        line = re.match(r'^(\d+) (-?\d+) (-?\d+) (-?\d+)$', sys.stdin.readline())
        assert line, 'Does not match with regexp'
        t, a, b, c = map(int, line.groups())
        if t == 1:
            assert 0 <= a <= 20000000000, 'l out of range: %d' % a
            assert 0 <= b <= 20000000000, 'r out of range: %d' % b
            assert 0 <= c <= 359, 'theta out of range: %d' % c
        elif t == 2:
            assert 1 <= a <= N, 'a out of range: %d' % a
            assert 1 <= b <= N, 'b out of range: %d' % b
            assert 1 <= c <= N, 'c out of range: %d' % c
        else:
            assert False, 't out of range: %d' % t
        


    assert sys.stdin.read() == '', 'Extra lines'

if __name__ == '__main__':
    main()
