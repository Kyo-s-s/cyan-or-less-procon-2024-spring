#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {

    ll X; cin >> X;
    string S; cin >> S;    
    assert(X <= 8);

    ll ans = 0;
    vector<string> cyanstrs;
    for (char a = 'a'; a <= 'z'; a++) {
        for (char b = 'a'; b <= 'z'; b++) {
            for (char c = 'a'; c <= 'z'; c++) {
                for (char d = 'a'; d <= 'z'; d++) {
                    cyanstrs.push_back(a + b + c + d + "cyan");
                    cyanstrs.push_back(a + b + c + "cyan" + d);
                    cyanstrs.push_back(a + b + "cyan" + c + d);
                    cyanstrs.push_back(a + "cyan" + b + c + d);
                    if ("" + a + b + c + d == "cyan") continue;
                    cyanstrs.push_back("cyan" + a + b + c + d);
                }
            }
        }
    }

    for (auto s : cyanstrs) {
        if ((int)s.length() <= X && s <= S) ans++;
    }

    cout << ans << endl;

}