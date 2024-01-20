#include<bits/stdc++.h>
using namespace std;

using ll = long long;

ll mod = 998;
ll x = 1;

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

ll number(string S) {
    if (S == "x") {
        return x;
    }
    ll res = 0;
    for (auto c : S) {
        res = res * 10 + c - '0';
    }
    return res;
}

vector<string> splitAdd(string S) {
    vector<string> res = {""};
    for (auto c : S) {
        if (c == '+') res.push_back("");
        else res.back().push_back(c);
    }
    return res;
}

vector<string> splitProd(string S) {
    vector<string> res = {""};
    for (auto c : S) {
        if (c == '*') res.push_back("");
        else res.back().push_back(c);
    }
    return res;
}

vector<string> splitFactor(string S) {
    vector<string> res = {""};
    for (auto c : S) {
        if (c == '^') res.push_back("");
        else res.back().push_back(c);
    }
    return res;
}



int main() {

    ll K; cin >> K;
    string S; cin >> S;

    vector<string> add = splitAdd(S);
    vector<vector<string>> prod(add.size());
    for (int i = 0; i < (int)add.size(); i++) {
        prod[i] = splitProd(add[i]);
    }

    auto eval = [&]() {
        ll ans = 0;
        for (auto ad : prod) {
            ll a = 1;
            for (auto pr : ad) {
                auto fc = splitFactor(pr);
                if (fc.size() == 1) {
                    a = a * number(fc[0]) % mod;
                } else {
                    a = a * pow(number(fc[0]) % mod, number(fc[1])) % mod;
                }
            }
            ans = (ans + a) % mod;
        }
        x = ans;
    };

    ll m = 62;
    vector doubling(m, vector<ll>(mod));
    for (int i = 0; i < mod; i++) {
        x = i;
        eval();
        doubling[0][i] = x;
    }

    for (int k = 0; k < m - 1; k++) {
        for (int i = 0; i < mod; i++) {
            doubling[k+1][i] = doubling[k][doubling[k][i]];
        }
    }

     x = 1;
    for (int k = 0; K > 0; k++) {
        if (K & 1) x = doubling[k][x];
        K >>= 1;
    }

    cout << x << endl;

}
