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

int64_t f_dijkstra(int H, int W, int r_k, int c_k, int r_b, int c_b){
    //これを使うのは (H==3 && dy < 5) のとき
    //そのため2つのコマは3*4の長方形に収まっている
    //盤が3*4以上のときナイトは全てのマスに移動可能なので、ans <= 11 or ans == INF
    //いずれかのコマから見て横方向の距離が22より大きいマスは集合場所になりえない

    int L = 0;
    chmax(L, c_k - 22);
    chmax(L, c_b - 22);
    int R = W;
    chmin(R, c_k + 23);
    chmin(R, c_b + 23);

    vector<vector<int64_t>> D_k(H, vector<int64_t>(R-L, INF));
    vector<vector<int64_t>> D_b(H, vector<int64_t>(R-L, INF));

    queue<pair<int,int>> q_k;
    q_k.push({r_k, c_k});
    D_k[r_k][c_k] = 0;
    while(q_k.size()){
        auto[x, y] = q_k.front();
        q_k.pop();
        for(auto [dx, dy] : dir_k){
            int nx = x + dx;
            int ny = y + dy;
            if(nx < 0 || H <= nx || ny < L || R <= ny) continue;
            if(chmin(D_k[nx][ny-L], D_k[x][y-L] + 1)) q_k.push({nx, ny});
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
            if(nx < 0 || H <= nx || ny < L || R <= ny) continue;
            if(chmin(D_b[nx][ny-L], D_b[x][y-L] + 1)) q_b.push({nx, ny});
        }
    }

    int64_t ans = INF;
    for(int i = 0; i < H; i++){
        for(int j = L; j < R; j++){
            chmin(ans, D_k[i][j-L]+D_b[i][j-L]);
        }
    }
    return ans;
}

//ナイトしか動かさない
int64_t f_k(int H, int W, int r_k, int c_k, int r_b, int c_b){
    if(r_k < 0 || H <= r_k) return INF;
    if(c_k < 0 || W <= c_k) return INF;
    if(r_b < 0 || H <= r_b) return INF;
    if(c_b < 0 || W <= c_b) return INF;
    if(H == 2){
        int dx = abs(r_b-r_k);
        int dy = abs(c_b-c_k);
        if(dy % 4 == 0 && dx == 0) return dy / 2;
        if(dy % 4 == 2 && dx == 1) return dy / 2;
        return INF;
    }
    return INF;
}

int64_t f(int H, int W, int r_k, int c_k, int r_b, int c_b){
    if(H == 2){
        //ビショップは4回以上動かさない
        int64_t ans = INF;
        for(int i = -3; i <= 3; i++){
            int r_b_n = r_b;
            if(i%2 != 0) r_b_n = 1 - r_b;
            int c_b_n = c_b + i;
            chmin(ans, abs(i) + f_k(H, W, r_k, c_k, r_b_n, c_b_n));
        }
        return ans;
    }
    //dy>=5のとき1つの例外を除いてans=ceil(dy/2) (ビショップの横方向の移動距離が3以下で実現できる)
    int dx = abs(r_b-r_k);
    int dy = abs(c_b-c_k);
    if(dy < 5) return f_dijkstra(H, W, r_k, c_k, r_b, c_b);
    if(r_b == 1 && ((r_k == 1 && dy % 4 == 2) || (r_k != 1 && dy % 4 == 0))) return (dy+1)/2 + 1;
    return (dy+1)/2;
}

int main(){
    int H, W;
    int r_k, c_k, r_b, c_b;
    cin >> H >> W >> r_k >> c_k >> r_b >> c_b;
    r_k--; c_k--; r_b--; c_b--;

    int64_t ans = f(H, W, r_k, c_k, r_b, c_b);
    if(ans == INF) ans = -1;

    cout << ans << endl;
}
