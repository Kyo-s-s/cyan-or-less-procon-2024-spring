#!/usr/bin/env python3

import re
import sys

def main():
    line = re.match(r'^#[0-9a-f]{6}$', sys.stdin.readline())
    assert line, 'Does not match with regexp'


if __name__ == '__main__':
    main()