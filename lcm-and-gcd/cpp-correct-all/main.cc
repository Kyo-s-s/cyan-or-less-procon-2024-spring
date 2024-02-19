#include <bits/stdc++.h>
using namespace std;

template <typename T>
T exEuclid(T a, T b, T &x, T &y){
    T d = a;
    if(b != 0){
        d = exEuclid(b, a%b, y, x);
        y -= (a/b)*x;
    }
    else{
        x = 1;
        y = 0;
    }
    //cout << a << " * " << x << " + " << b << " * " << y << " = " << d << endl;
    return d;
}

int64_t mod;
struct modint{
    int64_t n;
    int64_t p;

    modint(){
        n = 0;
        p = mod;
    }
    modint(int64_t a){
        if(a <= -mod) a %= mod;
        else if(a >= mod) a %= mod;
        if(a < 0) a += mod;
        n = a;
        p = mod;
    }
    modint(int64_t a, int64_t q){
        if(a <= -q) a %= q;
        else if(a >= q) a %= q;
        if(a < 0) a += q;
        n = a;
        p = q;
    }

    modint pow(int64_t a){
        if(a <= 1-p) a %= p-1;
        else if(a >= p-1) a %= p-1;
        if(a < 0) a += p-1;

        modint rtn;
        if(n == 0) {
            rtn.n = 0;
            return rtn;
        }
        if(n == 1) {
            rtn.n = 1;
            return rtn;
        }
        if(a == 0) {
            rtn.n = 1;
            return rtn;
        }
        if(a == 1) {
            rtn.n = n;
            return rtn;
        }

        int64_t b = a/2;
        int64_t c = a%2;
        rtn = pow(b);
        rtn *= rtn;
        if(c){
            rtn *= modint(n);
        }
        return rtn;
    }

    bool operator==(modint other){
        return n == other.n && p == other.p;
    }
    bool operator!=(modint other){
        return !(n == other.n && p == other.p);
    }

    modint operator+(modint other){
        modint rtn(n+other.n, p);
        return rtn;
    }
    modint operator-(modint other){
        modint rtn(n-other.n, p);
        return rtn;
    }
    modint operator*(modint other){
        modint rtn(n*other.n, p);
        return rtn;
    }
    modint operator/(modint other){
        int64_t x, y, d;
        d = exEuclid(other.n, p, x, y);
        int64_t rtn = x*n;
        if(d > 1) rtn /= d;
        return modint(rtn);
    }

    void operator+=(modint other){
        n += other.n;
        if(n >= p) n %= p;
    }
    void operator-=(modint other){
        n -= other.n;
        if(n < 0) n += p;
    }
    void operator*=(modint other){
        n *= other.n;
        if(n >= p) n %= p;
    }
    void operator/=(modint other){
        int64_t x, y, d;
        d = exEuclid(other.n, p, x, y);
        n *= x;
        if(d > 1) n /= d;
        if(n <= p || p <= n) n %= p;
        if(n < 0) n += p;
        return;
    }
    void operator++(){
        n++;
        if(n == p) n = 0;
        return;
    }
    void operator--(){
        n--;
        if(n == -1) n = p-1;
        return;
    }
};

vector<modint> fact_mod_v;
vector<modint> inv_fact_mod_v;

vector<int64_t> P;

void init_P(int64_t x){
    for(int i = 2; i <= x; i++){
        bool b = true;
        for(int64_t p : P){
            if(i%p == 0){
                b = false;
                break;
            }
            if(i < p*p) break;
        }
        if(b) P.push_back(i);
    }
}

int main(){
    mod = 998244353;
    init_P(32000);

    int N; cin >> N;
    vector<int> A(N);
    for(auto &a : A) cin >> a;

    map<int64_t, vector<int>> mp;
    for(auto a : A){
        for(auto p : P){
            int e = 0;
            while(a%p == 0){
                a /= p;
                e++;
            }
            if(e > 0) mp[p].push_back(e);
            if(a < p*p) break;
        }
        if(a > 1) mp[a].push_back(1);
    }

    vector<modint> B(N, 1);
    for(auto[p, v] : mp){
        sort(v.begin(), v.end());
        int sz = v.size();
        for(int i = 0; i < sz; i++){
            B[i+N-sz] *= modint(p).pow(v[i]);
        }
    }

    for(int i = 0; i < N; i++){
        if(i) cout << " ";
        cout << B[i].n;
    }
    cout << endl;
}
