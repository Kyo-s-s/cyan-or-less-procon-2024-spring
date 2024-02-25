#include<bits/stdc++.h>
using namespace std;

int main() {
    string S; cin >> S;

    auto read = [&](char x) -> int {
        if (0 <= x - '0' && x - '0' <= 9) return x - '0';
        return x - 'a' + 10;
    };

    auto conv = [&](char a, char b) -> int {
        return read(a) * 16 + read(b);
    };

    auto cmax = [&](string S) -> int {
        int r = conv(S[1], S[2]);
        int g = conv(S[3], S[4]);
        int b = conv(S[5], S[6]);
        return max(max(r, g), b);
    };

    auto cmin = [&](string S) -> int {
        int r = conv(S[1], S[2]);
        int g = conv(S[3], S[4]);
        int b = conv(S[5], S[6]);
        return min(min(r, g), b);
    };

    string cyan = "#00c0c0";

    // (cmax(S) - cmin(S)) / cmax(S) <= (cmax(cyan) - cmin(cyan)) / cmax(cyan) 
    if ((cmax(S) - cmin(S)) * cmax(cyan) <= (cmax(cyan) - cmin(cyan)) * cmax(S)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

}
