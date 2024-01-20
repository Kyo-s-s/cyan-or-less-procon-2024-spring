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

    int K = N + M;
    auto uni = [&](int i) -> int { return i + N; };
    vector<vector<edge>> G(K);
    for (int i = 0; i < M; i++) {
        for (int c = 0; c < C[i]; c++) {
            int a; cin >> a; a--;
            G[uni(i)].push_back(edge{a, D[i]});
            G[a].push_back(edge{uni(i), 0});
        }
    }

    vector<ll> dist(K, INF);
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