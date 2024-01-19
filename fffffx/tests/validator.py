#!/usr/bin/python3

import re
import sys

def main():
    m = re.match(r'(\d+)\n([x\d\^\+\*]+)\n$', sys.stdin.read())
    assert m, 'Does not match with regexp'
    K, S = m.groups()
    K = int(K)
    assert 1 <= K <= 1_000_000_000_000_000_000, 'X out of range: %d' % K
    assert 1 <= len(S) <= 100, 'S.length out of range: %s' % S


if __name__ == '__main__':
    main()
