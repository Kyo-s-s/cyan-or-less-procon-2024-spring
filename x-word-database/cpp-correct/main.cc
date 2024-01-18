#include<bits/stdc++.h>
using namespace std;

using ll = long long;

template<int m> struct StaticModint{
    using mint = StaticModint;
  public:
    static constexpr int mod() { return m; }
    static mint raw(int v) {
        mint x;
        x._v = v;
        return x;
    }

    StaticModint() : _v(0) {}
    template <class T>
    StaticModint(T v) {
        long long x = (long long)(v % (long long)(umod()));
        if (x < 0) x += umod();
        _v = (unsigned int)(x);
    }

    unsigned int val() const { return _v; }

    mint& operator++() {
        _v++;
        if (_v == umod()) _v = 0;
        return *this;
    }
    mint& operator--() {
        if (_v == 0) _v = umod();
        _v--;
        return *this;
    }
    mint operator++(int) {
        mint result = *this;
        ++*this;
        return result;
    }
    mint operator--(int) {
        mint result = *this;
        --*this;
        return result;
    }

    mint& operator+=(const mint& rhs) {
        _v += rhs._v;
        if (_v >= umod()) _v -= umod();
        return *this;
    }
    mint& operator-=(const mint& rhs) {
        _v -= rhs._v;
        if (_v >= umod()) _v += umod();
        return *this;
    }
    mint& operator*=(const mint& rhs) {
        unsigned long long z = _v;
        z *= rhs._v;
        _v = (unsigned int)(z % umod());
        return *this;
    }
    mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }

    mint operator+() const { return *this; }
    mint operator-() const { return mint() - *this; }

    mint pow(long long n) const {
        assert(0 <= n);
        mint x = *this, r = 1;
        while (n) {
            if (n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
    mint inv() const {
        assert(_v);
        return pow(umod() - 2);
    }

    friend mint operator+(const mint& lhs, const mint& rhs) { return mint(lhs) += rhs;}
    friend mint operator-(const mint& lhs, const mint& rhs) { return mint(lhs) -= rhs; }
    friend mint operator*(const mint& lhs, const mint& rhs) { return mint(lhs) *= rhs; }
    friend mint operator/(const mint& lhs, const mint& rhs) { return mint(lhs) /= rhs; }
    friend bool operator==(const mint& lhs, const mint& rhs) { return lhs._v == rhs._v; }
    friend bool operator!=(const mint& lhs, const mint& rhs) { return lhs._v != rhs._v; }

    friend ostream &operator<<(ostream &os, mint x) {
        os << x.val();
        return (os);
    }

  private:
    unsigned int _v;
    static constexpr unsigned int umod() { return m; }

};

using Modint998244353 = StaticModint<998244353>;
using Modint1000000007 = StaticModint<1000000007>;

using Mint = Modint998244353;

int main() {

    ll X; cin >> X;
    string S; cin >> S;
    while ((int)S.size() < X) S += '`'; 

    vector dp(2, vector<Mint>(5));
    // dp[i][j] に対し...
    // i = 0: tight
    // i = 1: smaller
    // j = 0: ...[^c] かつ cyan を含まない
    // j = 1: ...c かつ cyan を含まない
    // j = 2: ..cy かつ cyan を含まない
    // j = 3: .cya かつ cyan を含まない
    // j = 4: cyan を含む 

    dp[0][0] = 1;
    Mint ans = 0;
    for (int x = 0; x < X; x++) {
        vector pd(2, vector<Mint>(5));
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j <= 4; j++) {
                for (char c = 'a'; c <= 'z'; c++) {
                    int ni = [&]() {
                        if (i == 0 && c == S[x]) return 0;
                        if (i == 0 && c > S[x]) return -1;
                        return 1;
                    }();
                    if (ni == -1) continue;
                    int nj = [&]() {
                        if (j == 4) return 4;
                        if (c == 'c') return 1;
                        if (j == 1 && c == 'y') return 2;
                        if (j == 2 && c == 'a') return 3;
                        if (j == 3 && c == 'n') return 4;
                        return 0;
                    }();
                    pd[ni][nj] += dp[i][j];
                }
            }
        }
        dp = pd;
        ans += dp[0][4] + dp[1][4];
    }

    cout << ans.val() << endl;

}
