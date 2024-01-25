#!/usr/bin/env python3

import re
import sys

def main():
    m = re.match(r'(\d+)\n(\w+)\n$', sys.stdin.read())
    assert m, 'Does not match with regexp'
    X, S = m.groups()
    X = int(X)
    assert 4 <= X <= 100000, 'X out of range: %d' % X
    assert 1 <= len(S) <= X, 'S.length out of range: %s' % S


if __name__ == '__main__':
    main()
