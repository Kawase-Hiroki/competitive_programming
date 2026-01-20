/*
atcoder abc441 A - Brack Square
username peace10 == Kawase-Hiroki
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int p, q, x, y;
    cin >> p >> q >> x >> y;

    if (p <= x && q <= y && x < p + 100 && y < q + 100) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
