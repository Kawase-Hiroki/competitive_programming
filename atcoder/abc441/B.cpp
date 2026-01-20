/*
atcoder abc441 B - Two Languages
username peace10 == Kawase-Hiroki
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    string s, t;
    cin >> n >> m >> s >> t;
    int q;
    cin >> q;
    while (q--) {
        string w;
        cin >> w;
        bool Takahashi = true;
        bool Aoki = true;
        for (int i = 0; i < w.size(); i++) {
            bool ok = false;
            for (int j = 0; j < n; j++) {
                if (w[i] == s[j]) {
                    ok = true;
                }
            }
            if (!ok) {
                Takahashi = false;
            }
        }
        for (int i = 0; i < w.size(); i++) {
            bool ok = false;
            for (int j = 0; j < m; j++) {
                if (w[i] == t[j]) {
                    ok = true;
                }
            }
            if (!ok) {
                Aoki = false;
            }
        }
        if (Takahashi && Aoki) {
            cout << "Unknown" << endl;
        } else if (Aoki) {
            cout << "Aoki" << endl;
        } else {
            cout << "Takahashi" << endl;
        }
    }
}