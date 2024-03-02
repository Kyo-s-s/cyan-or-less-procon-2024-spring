#!/usr/bin/env pypy3

def cmb(n, r, mod):
    if ( r<0 or r>n ):
        return 0
    r = min(r, n-r)
    return g1[n] * g2[r] * g2[n-r] % mod

mod = 998244353 #出力の制限
N = 202020
g1 = [1, 1] # 元テーブル
g2 = [1, 1] #逆元テーブル
inverse = [0, 1] #逆元テーブル計算用テーブル

for i in range( 2, N + 1 ):
    g1.append( ( g1[-1] * i ) % mod )
    inverse.append( ( -inverse[mod % i] * (mod//i) ) % mod )
    g2.append( (g2[-1] * inverse[-1]) % mod )

def nHk(n, k):
    return cmb(n+k-1, k, mod)

X = int(input())
S = input()

ans = 0

for x in range(4, X + 1):
    for k in range(1, x // 4 + 1):
        ans += (1 if k % 2 == 1 else -1) * nHk(k + 1, x - 4 * k) * pow(26, x - 4 * k, mod)


print(ans % mod)
