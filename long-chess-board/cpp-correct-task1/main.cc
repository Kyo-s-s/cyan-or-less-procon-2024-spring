#include <bits/stdc++.h>
using namespace std;

template <typename T>
bool chmin(T &a, const T& b) {
    if (a > b) {
        a = b;  // aをbで更新
        return true;
    }
    return false;
}

template <typename T>
bool chmax(T &a, const T& b) {
    if (a < b) {
        a = b;  // aをbで更新
        return true;
    }
    return false;
}

int64_t INF = 1001002003004;
vector<pair<int,int>> dir_k = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
vector<pair<int,int>> dir_b = {{1, 1}, {2, 2}, {-1, 1}, {-2, 2}, {-1, -1}, {-2, -2}, {1, -1}, {2, -2}};

int64_t f_bfs(int H, int W, int r_k, int c_k, int r_b, int c_b){
    vector<vector<int64_t>> D_k(H, vector<int64_t>(W, INF));
    vector<vector<int64_t>> D_b(H, vector<int64_t>(W, INF));

    queue<pair<int,int>> q_k;
    q_k.push({r_k, c_k});
    D_k[r_k][c_k] = 0;
    while(q_k.size()){
        auto[x, y] = q_k.front();
        q_k.pop();
        for(auto [dx, dy] : dir_k){
            int nx = x + dx;
            int ny = y + dy;
            if(nx < 0 || H <= nx || ny < 0 || W <= ny) continue;
            if(chmin(D_k[nx][ny], D_k[x][y] + 1)) q_k.push({nx, ny});
        }
    }

    queue<pair<int,int>> q_b;
    q_b.push({r_b, c_b});
    D_b[r_b][c_b] = 0;
    while(q_b.size()){
        auto[x, y] = q_b.front();
        q_b.pop();
        for(auto [dx, dy] : dir_b){
            int nx = x + dx;
            int ny = y + dy;
            if(nx < 0 || H <= nx || ny < 0 || W <= ny) continue;
            if(chmin(D_b[nx][ny], D_b[x][y] + 1)) q_b.push({nx, ny});
        }
    }

    int64_t ans = INF;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            chmin(ans, D_k[i][j]+D_b[i][j]);
        }
    }
    return ans;
}

int main(){
    int T; cin >> T;
    for(int i = 0; i < T; i++){
        int H, W;
        int r_k, c_k, r_b, c_b;
        cin >> H >> W >> r_k >> c_k >> r_b >> c_b;
        r_k--; c_k--; r_b--; c_b--;

        assert(H == 2);

        int64_t ans = f_bfs(H, W, r_k, c_k, r_b, c_b);
        if(ans == INF) ans = -1;
        
        cout << ans << endl;
    }
}
