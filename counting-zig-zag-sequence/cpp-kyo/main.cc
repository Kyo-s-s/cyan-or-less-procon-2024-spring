#include<bits/stdc++.h>
using namespace std;

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

    int N, K; cin >> N >> K;

    if (N == 1) {
        cout << Mint(K) << endl;
        exit(0);
    }

    if (N == 2) {
        cout << Mint(K) * Mint(K - 1) << endl;
        exit(0);
    }

    vector<Mint> inc(K), dec(K);
    for (int a = 0; a < K; a++) {
        for (int b = 0; b < K; b++) {
            if (a > b) dec[b] += 1;
            if (a < b) inc[b] += 1;
        }
    }

    for (int x = 2; x < N; x++) {
        vector<Mint> ninc(K), ndec(K);

        vector<Mint> cinc(K + 1), cdec(K + 1);
        for (int k = 0; k < K; k++) {
            cinc[k + 1] = cinc[k] + inc[k];
            cdec[k + 1] = cdec[k] + dec[k];
        }

        for (int k = 0; k < K; k++) {
            ninc[k] = cdec[k];
            ndec[k] = cinc[K] - cinc[k + 1];
        }

        // for (int a = 0; a < K; a++) {
        //     for (int b = 0; b < K; b++) {
        //         if (a > b) ndec[b] += inc[a];
        //         if (a < b) ninc[b] += dec[a];
        //     }
        // }


        swap(inc, ninc);
        swap(dec, ndec);
    }

    Mint ans = 0;
    for (int a = 0; a < K; a++) {
        ans += inc[a];
        ans += dec[a];
    }

    cout << ans << endl;


}
