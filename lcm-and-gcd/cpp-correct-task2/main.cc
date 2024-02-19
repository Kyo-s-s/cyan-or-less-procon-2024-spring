#include <bits/stdc++.h>
using namespace std;

template<typename T>
void printv(vector<T> &v){
    bool b = false;
    for(auto i : v){
        if(b) cout << " ";
        else b = true;
        cout << i;
    }
    cout << endl;
}

int main(){
    int64_t mod = 998244353;
    int N; cin >> N;

    if(N > 1000) return 0;
    
    vector<int64_t> A(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }

    for(int i = 0; i < N; i++){
        for(int j = i; j < N-1; j++){
            int64_t g = gcd(A[j], A[j+1]);
            int64_t l = lcm(A[j], A[j+1]);
            A[j] = g;
            A[j+1] = l;
        }
    }

    for(auto &a : A) a %= mod;

    printv(A);
}
