#include <bits/stdc++.h>
using namespace std;

int64_t my_gcd(int64_t x, int64_t y){
    if(x > y) swap(x, y);
    if(x == 0) return y;
    return my_gcd(y%x, x);
}

int main(){
    int64_t mod = 998244353;
    int N; cin >> N;
    vector<int64_t> A(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }

    if(N == 2){
        int64_t x = my_gcd(A[0], A[1]);
        int64_t y = A[0] * (A[1] / x);
        A[0] = x;
        A[1] = y % mod;
        for(int i = 0; i < N; i++){
            if(i) cout << " ";
            cout << A[i];
        }
        cout << endl;
    }
}
