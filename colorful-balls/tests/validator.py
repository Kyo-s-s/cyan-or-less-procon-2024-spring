#!/usr/bin/env python3

import re
import sys

def main():
    line = re.match(r'^(\d+)$', sys.stdin.readline())
    assert line, 'Does not match with regexp'
    Q = int(line.groups()[0])
    assert 1 <= Q <= 200000, 'T out of range: %d' % Q

    ballsNum = 0

    for _ in range(Q):
        readline = sys.stdin.readline()
        line = re.match(r'^(1 \d+ \d+|2 \d+|3 \d+)$', readline)
        assert line, 'Does not match with regexp'
        query = list(map(int, readline.split()))

        t = query[0]
        assert 1 <= t <= 3, 't out of range: %d' % t
        x = query[1]
        if t == 1:
            c = query[2]
            assert 1 <= c <= 1000000000, 'c out of range: %d' % c
            assert 1 <= x <= 1000000000, 'x out of range: %d' % x
            ballsNum += x
        elif t == 2:
            assert 1 <= x <= ballsNum, 'x out of range: %d' % x
            ballsNum -= x
        else:
            assert 1 <= x <= ballsNum, 'x out of range: %d' % x

    assert sys.stdin.read() == '', 'Extra lines'


if __name__ == '__main__':
    main()
