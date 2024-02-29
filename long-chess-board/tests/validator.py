#!/usr/bin/env python3

import re
import sys

def main():
    line = re.match(r'^(\d+)$', sys.stdin.readline())
    assert line, 'Does not match with regexp'
    T = int(line.groups()[0])
    assert 1 <= T <= 100000, 'T out of range: %d' % T

    for _ in range(T):
        line = re.match(r'^(\d+) (\d+)$', sys.stdin.readline())
        assert line, 'Does not match with regexp'
        H, W = map(int, line.groups())
        assert 2 <= H <= 3, 'H out of range: %d' % H
        assert H <= W <= 1000000000, 'W out of range: %d' % W

        line = re.match(r'^(\d+) (\d+) (\d+) (\d+)$', sys.stdin.readline())
        assert line, 'Does not match with regexp'
        r_k, c_k, r_b, c_b = map(int, line.groups())
        assert 1 <= r_k <= H, 'r_k out of range: %d' % r_k
        assert 1 <= c_k <= W, 'c_k out of range: %d' % c_k
        assert 1 <= r_b <= H, 'r_b out of range: %d' % r_b
        assert 1 <= c_b <= W, 'c_b out of range: %d' % c_b

    assert sys.stdin.read() == '', 'Extra lines'


if __name__ == '__main__':
    main()
