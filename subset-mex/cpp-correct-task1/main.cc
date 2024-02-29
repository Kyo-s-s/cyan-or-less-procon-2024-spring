#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {

    ll mod = 998244353;

    int N; cin >> N;
    vector<int> A(N);
    for (auto &a : A) cin >> a;

    assert(N <= 17);
    assert(all_of(A.begin(), A.end(), [](int a) { return 0 <= a && a <= 1000; }));

    ll ans = 0;


    for (ll msk = 0; msk < (1 << N); msk++) {
        set<int> S;
        for (int i = 0; i < N; i++) {
            if (msk & (1 << i)) {
                S.insert(A[i]);
            }
        }

        ll mex = 0;
        while (S.count(mex)) mex++;

        ans += mex;
        ans %= mod;

    }

    cout << ans << endl;


}