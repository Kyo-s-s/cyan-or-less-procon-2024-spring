#include<bits/stdc++.h>
using namespace std;

using ll = long long;

ll mod = 998;


ll pow(ll x, ll n) {
    ll ret = 1;
    while (n > 0) {
        if (n & 1) {
            ret *= x;
            ret %= mod;
        }
        x *= x;
        x %= mod;
        n >>= 1;  
    }
    return ret;
}

struct Parser {
    string S;
    int iter;
    int x;

    Parser(string S) : S(S + '!') {}

    ll solve(int v) {
        iter = 0;
        x = v;
        ll res = expr();
        assert(peek() == '!');
        return res;
    }

    char peek() {
        return S[iter];
    }
    char read() {
        return S[iter++];
    }
    bool consume(char a) {
        if (S[iter] == a) {
            iter++;
            return true;
        }
        return false;
    }

    ll expr() {
        ll res = term() % mod;
        while (consume('+')) {
            res += term();
            res %= mod;
        }
        return res;
    }

    ll term() {
        ll res = factor() % mod;
        while (consume('*')) {
            res *= factor();
            res %= mod;
        }
        return res;
    }

    ll factor() {
        ll res = value() % mod;
        if (consume('^')) {
            ll k = number();
            res = pow(res, k);
        }
        return res;
    }

    ll value() {
        if (consume('x')) return x;
        return number() % mod;
    }

    ll number() {
        ll res = 0;
        while (true) {
            char p = peek();
            if ('0' <= p && p <= '9') {
                assert(!(res == 0 && p == '0'));
                res = res * 10 + (p - '0');
                read();
            } else {
                break;
            }
        }
        assert(res < 1000000000LL);
        return res;
    }
};

int main() {

    cout << "WA!!!!!!!!" << endl;

    ll K; cin >> K;
    string S; cin >> S;

    Parser parser(S);

    ll m = 62;
    vector doubling(m, vector<ll>(mod));
    for (int i = 0; i < mod; i++) {
        doubling[0][i] = parser.solve(i);
    }

    for (int k = 0; k < m - 1; k++) {
        for (int i = 0; i < mod; i++) {
            doubling[k+1][i] = doubling[k][doubling[k][i]];
        }
    }

    ll x = 1;
    for (int k = 0; K > 0; k++) {
        if (K & 1) x = doubling[k][x];
        K >>= 1;
    }

    cout << x << endl;
}
