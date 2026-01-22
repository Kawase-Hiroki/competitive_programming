/*
atcoder abc441 F - Must Buy
username peace10 == Kawase-Hiroki
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<long long> p(n), v(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i] >> v[i];
    }
    vector<vector<long long>> dp1(n + 1, vector<long long>(m + 1));
    vector<vector<long long>> dp2(n + 1, vector<long long>(m + 1));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= m; j++) {
            if (j < p[i])
                dp1[i + 1][j] = dp1[i][j];
            if (j >= p[i])
                dp1[i + 1][j] = max(dp1[i][j], dp1[i][j - p[i]] + v[i]);
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= m; j++) {
            dp2[i][j] = dp2[i + 1][j];
            if (j >= p[i]) {
                dp2[i][j] = max(dp2[i][j], dp2[i + 1][j - p[i]] + v[i]);
            }
        }
    }

    string ans = "";

    long long target = dp1[n][m];
    for (int i = 0; i < n; i++) {
        long long max_woi = 0, max_wi = 0;

        for (int j = 0; j <= m; j++) {
            max_woi = max(max_woi, dp1[i][j] + dp2[i + 1][m - j]);
        }

        if (p[i] <= m) {
            for (int j = 0; j <= m; j++) {
                if (j + p[i] <= m) {
                    max_wi = max(max_wi,
                                 dp1[i][j] + dp2[i + 1][m - j - p[i]]);
                }
            }
        }

        if (max_woi < target)
            ans += 'A';
        else if (max_wi < target - v[i])
            ans += 'C';
        else
            ans += 'B';
    }

    cout << ans << endl;
}