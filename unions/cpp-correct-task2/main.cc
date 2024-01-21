#include<bits/stdc++.h>
using namespace std;

using ll = long long;
#define INF (1LL << 60)
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;

struct edge {
    int to;
    ll cost;
};

int main() {

    int N, M; cin >> N >> M;
    vector<int> C(M); for (auto &c : C) cin >> c;
    vector<ll> D(M); for (auto &d : D) cin >> d;

    assert(reduce(C.begin(), C.end(), 0, plus<int>()) <= 1000);

    vector<vector<edge>> G(N);
    for (int i = 0; i < M; i++) {
        vector<int> A(C[i]); 
        for (auto &a : A) cin >> a; 
        for (auto &a : A) a--;
        for (auto a : A) for (auto b : A) {
            if (a == b) continue;
            G[a].push_back(edge{b, D[i]});
        }
    }

    vector<ll> dist(N, INF);
    dist[0] = 0;
    min_priority_queue<pair<ll, int>> que;
    que.push({0, 0});

    while (!que.empty()) {
        auto [d, v] = que.top(); que.pop();
        if (dist[v] < d) continue;
        for (auto [nv, cost] : G[v]) {
            ll nd = d + cost;
            if (dist[nv] > nd) {
                dist[nv] = nd;
                que.push({nd, nv});
            }
        }
    }

    for (int i = 1; i < N; i++) {
        if (dist[i] == INF) cout << -1 << endl;
        else cout << dist[i] << endl;
    }

}
