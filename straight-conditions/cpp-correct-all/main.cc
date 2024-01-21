#include<bits/stdc++.h>
using namespace std;

struct UnionFind {
    int n, cnt;
    vector<int> parent;
    UnionFind() : n(0), cnt(0) {}
    UnionFind(int n) : n(n), cnt(n), parent(n, -1) {}

    int merge(int a, int b) {
        assert(0 <= a && a < n && 0 <= b && b < n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent[x] < -parent[y]) swap(x, y);
        parent[x] += parent[y];
        parent[y] = x;
        cnt--;
        return x;
    } 

    int leader(int a) {
        assert(0 <= a && a < n);
        if (parent[a] < 0) return a;
        return parent[a] = leader(parent[a]);
    }

    bool same(int a, int b) {
        assert(0 <= a && a < n && 0 <= b && b < n);
        return leader(a) == leader(b);
    }

    int size(int a) {
        assert(0 <= a && a < n);
        return -parent[leader(a)];
    }

    int count() { return cnt; }

    vector<vector<int>> groups() {
        vector<int> leader_buf(n), group_size(n);
        for (int i = 0; i < n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        vector<vector<int>> result(n);
        for (int i = 0; i < n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            remove_if(result.begin(), result.end(),
                      [&](const vector<int> &v) { return v.empty(); }),
            result.end());
        return result;
    }
};

int main() {

    int N, K; cin >> N >> K;    

    // i < j に対する i * N + j しか見ない
    UnionFind uf(N * N);

    auto edge = [&](int i, int j) {
        return i * N + j;
    };

    vector<tuple<int, int, int>> no;

    for (int k = 0; k < K; k++) {
        int t, a, b, c; cin >> t >> a >> b >> c;
        a--; b--; c--;
        if (t == 1) {
            uf.merge(edge(a, b), edge(a, c));
            uf.merge(edge(a, b), edge(b, c));
            uf.merge(edge(a, c), edge(b, c));
        } else {
            no.push_back({a, b, c});
        }
    }

    bool ans = true;

    for (auto [a, b, c] : no) {
        if (
            uf.same(edge(a, b), edge(a, c)) &&
            uf.same(edge(a, b), edge(b, c)) &&
            uf.same(edge(a, c), edge(b, c))
        ) {
            ans = false;
        }
    }

    cout << (ans ? "Yes" : "No") << endl;
}