#include<bits/stdc++.h>
using namespace std;

int main() {

    int N; cin >> N;
    vector<int> A(N);
    for (auto &a : A) cin >> a;
    int Q; cin >> Q;

    vector<pair<int, optional<int>>> query(Q);

    for (auto &[c, v] : query) {
        string s; cin >> s;

        if (s == "push_back") {
            c = 1;
            int x; cin >> x;
            v = x;
        }

        if (s == "pop_back") {
            c = 2;
            int x; cin >> x;
        }

        if (s == "push_front") {
            c = 3;
            int x; cin >> x;
            v = x;
        }

        if (s == "pop_front") {
            c = 4;
            int x; cin >> x;
        }
    }

    // output
    cout << N << endl;
    for (int i = 0; i < N; i++) {
        cout << A[i] << " \n"[i == N - 1];
    }
    cout << Q << endl;
    for (auto [c, v] : query) {
        cout << c;
        if (v) {
            cout << " " << *v;
        }
        cout << endl;
    }

}
