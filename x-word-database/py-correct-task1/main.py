#!/usr/bin/env pypy3

X = int(input())
S = input()

ans = 0

def check(s):
    global ans
    if len(s) <= X and s <= S:
        ans += 1

check('cyan')

for ai in range(ord('a'), ord('z') + 1):
    a = chr(ai)
    check(a + 'cyan')
    check('cyan' + a)

    for bi in range(ord('a'), ord('z') + 1):
        b = chr(bi)
        check(a + b + 'cyan')
        check(a + 'cyan' + b)
        check('cyan' + a + b)

        for ci in range(ord('a'), ord('z') + 1):
            c = chr(ci)
            check(a + b + c + 'cyan')
            check(a + b + 'cyan' + c)
            check(a + 'cyan' + b + c)
            check('cyan' + a + b + c)

            for di in range(ord('a'), ord('z') + 1):

                d = chr(di)
                check(a + b + c + d + 'cyan')
                check(a + b + c + 'cyan' + d)
                check(a + b + 'cyan' + c + d)
                check(a + 'cyan' + b + c + d)
                if (a + b + c + d == "cyan"): continue
                check('cyan' + a + b + c + d)



print(ans)
