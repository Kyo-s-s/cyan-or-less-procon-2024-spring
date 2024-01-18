#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {

    ll X; cin >> X;
    string S; cin >> S;    
    assert(X <= 8);

    ll ans = 0;
    vector<string> cyanstrs = {"cyan"};

    for (char a = 'a'; a <= 'z'; a++) {
        string x = string(1, a);

        cyanstrs.push_back(x + "cyan");
        cyanstrs.push_back("cyan" + x);

        for (char b = 'a'; b <= 'z'; b++) {
            string y = string(1, b);

            cyanstrs.push_back(x + y + "cyan");
            cyanstrs.push_back(x + "cyan" + y);
            cyanstrs.push_back("cyan" + x + y);


            for (char c = 'a'; c <= 'z'; c++) {
                string z = string(1, c);

                cyanstrs.push_back(x + y + z + "cyan");
                cyanstrs.push_back(x + y + "cyan" + z);
                cyanstrs.push_back(x + "cyan" + y + z);
                cyanstrs.push_back("cyan" + x + y + z);

                for (char d = 'a'; d <= 'z'; d++) {
                    string w = string(1, d);

                    cyanstrs.push_back(x + y + z + w + "cyan");
                    cyanstrs.push_back(x + y + z + "cyan" + w);
                    cyanstrs.push_back(x + y + "cyan" + z + w);
                    cyanstrs.push_back(x + "cyan" + y + z + w);
                    if (x + y + z + w == "cyan") continue;
                    cyanstrs.push_back("cyan" + x + y + z + w);
                }
            }
        }
    }

    for (auto s : cyanstrs) {
        if ((int)s.length() <= X && s <= S) ans++;
    }

    cout << ans << endl;

}
