/*
atcoder abc441 D - Paid Walk
username peace10 == Kawase-Hiroki
*/

#include <bits/stdc++.h>
using namespace std;

#define N (int)200000

int l, s, t;
vector<pair<int, int>> g[N];
bool flag[N];

void dfs(int pos, int len, int sum) {
    if (len == l) {
        if ((s <= sum) && (sum <= t))
            flag[pos] = true;
        return;
    }
    if (len < l) {
        for (int i = 0; i < g[pos].size(); i++) {
            dfs(g[pos][i].first, len + 1, sum + g[pos][i].second);
        }
    }
    return;
}

int main() {
    int n, m;
    cin >> n >> m >> l >> s >> t;
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        g[u-1].push_back({v-1, c});
    }
    for (int i = 0; i < n; i++) {
        flag[i] = false;
    }
    dfs(0, 0, 0);

    for (int i = 0; i < n; i++) {
        if (flag[i]) {
            cout << i + 1 << " ";
        }
    }
    cout<<endl;
}