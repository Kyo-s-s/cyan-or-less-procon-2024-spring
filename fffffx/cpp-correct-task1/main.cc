#include<bits/stdc++.h>
using namespace std;

using ll = long long;

ll mod = 998;
ll x = 1;

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

int main() {

    ll K; cin >> K;
    string S; cin >> S;

    assert(K == 1);
    assert(all_of(S.begin(), S.end(), [](char c) {
        return (c != '*' && c != '^');
    }));

    auto add = splitAdd(S);
    ll ans = 0;
    for (auto s : add) {
        ans += number(s);
        ans %= mod;
    }

    cout << ans << endl;

}
