#!/usr/bin/env pypy3


mod = 998244353
class Divisor:
    def __init__(self, n):
        self.min_factor = [0] * (n + 1)
        self.min_factor[1] = 1
        for i in range(2, n + 1):
            if self.min_factor[i] == 0:
                self.min_factor[i] = i
                for j in range(i * i, n + 1, i):
                    if self.min_factor[j] == 0:
                        self.min_factor[j] = i

    def divisors(self, x):
        res = {}
        while x > 1:
            if self.min_factor[x] in res:
                res[self.min_factor[x]] += 1
            else:
                res[self.min_factor[x]] = 1
            x //= self.min_factor[x]
        return res


div = Divisor(202020)

N = int(input())
A = list(map(int, input().split()))

mp = {}

for a in A:
    for k, v in div.divisors(a).items():
        if k in mp:
            mp[k].append(v)
        else:
            mp[k] = [v]

ans = [1 for _ in range(N)]
for k, v in mp.items():
    v.sort()
    v.reverse()
    for i in range(len(v)):
        ans[i] = ans[i] * pow(k, v[i], mod) % mod

ans.reverse()
print(*ans)


# --- 以下、cpp-correct-all/main.cc の移植 ---
# ERROR: lcm-and-gcd/py-correct-all: all_max_N_100k_A_200k_02.in: Time Limit Exceeded
# ERROR: lcm-and-gcd/py-correct-all: all_rand_N_100k_A_200k_01.in: Time Limit Exceeded

# mod = 998244353

# def get_primes(n):
#     primes = []
#     for i in range(2, n+1):
#         is_prime = True
#         for p in primes:
#             if p*p > i:
#                 break
#             if i % p == 0:
#                 is_prime = False
#                 break
#         if is_prime:
#             primes.append(i)
#     return primes


# primes = get_primes(1000)

# N = int(input())
# A = list(map(int, input().split()))

# mp = {}

# for a in A:
#     for p in primes:
#         cnt = 0
#         while a % p == 0:
#             a //= p
#             cnt += 1

#         if cnt > 0:
#             if p in mp:
#                 mp[p].append(cnt)
#             else:
#                 mp[p] = [cnt]
        
#     if a > 1:
#         if a in mp:
#             mp[a].append(1)
#         else:
#             mp[a] = [1]

# ans = [1 for _ in range(N)]
# for [k, v] in mp.items():
#     v.sort()
#     v.reverse()
#     for i in range(len(v)):
#         ans[i] = ans[i] * pow(k, v[i], mod) % mod

# ans.reverse()
# print(*ans)
