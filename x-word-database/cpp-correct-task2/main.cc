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


template<class T> struct Enumeration{
  public:
    Enumeration(int sz = 0) { update(sz); }

    T fact(int k) {
        update(k);
        return _fact[k];
    }

    T finv(int k) {
        update(k);
        return _finv[k];
    }

    T inv(int k) {
        update(k);
        return _inv[k];
    }

    T nPk(int n, int k) {
        if(k < 0 || n < k) return 0;
        return fact(n) * finv(n - k);
    }

    T nCk(int n, int k) {
        if(k < 0 || n < k) return 0;
        return fact(n) * finv(k) * finv(n - k);
    }

    T nHk(int n, int k) {
        if(n < 0 || k < 0) return 0;
        if(n == 0) return 1;
        else return nCk(n + k - 1, k);
    }

    T Catalan(int n){
        return nCk(2*n, n) - nCk(2*n, n-1);
    }

  private:
    vector<T> _fact, _finv, _inv;

    void update(int sz) {
        if((int)_fact.size() < sz + 1){
            int pre_sz = max(1, (int)_fact.size());
            _fact.resize(sz + 1, T(1));
            _finv.resize(sz + 1, T(1));
            _inv.resize(sz + 1, T(1));
            for(int i = pre_sz; i <= (int)sz; i++) {
                _fact[i] = _fact[i - 1] * T(i);
            }
            _finv[sz] = T(1) / _fact[sz];
            for(int i = (int)sz - 1; i >= pre_sz; i--) {
                _finv[i] = _finv[i + 1] * T(i + 1);
            }
            for(int i = pre_sz; i <= (int)sz; i++) {
                _inv[i] = _finv[i] * _fact[i - 1];
            }
        }
    }

};

int main() {

    ll X; cin >> X;
    string S; cin >> S;    
    assert(X <= 1000);
    assert(S == string(X, 'z'));

    Enumeration<Mint> enu;

    Mint ans = 0;

    for (int x = 4; x <= X; x++) {
        for (int k = 1; k * 4 <= x; k++) {
            ans += (k % 2 == 1 ? 1 : -1) * enu.nHk(k + 1, x - 4 * k) * Mint(26).pow(x - 4 * k);
        }
    }

    cout << ans << endl;

}
