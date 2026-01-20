/*
atcoder abc441 B - Two Languages
username peace10 == Kawase-Hiroki
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    long long x;
    cin >> n >> k >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater<long long>());
    long long sum = 0;
    int l = 0;
    for (int i = 0; i < n; i++) {
        l++;
        if (i < n - k)
            continue;
        sum += a[i];
        if (sum >= x)
            break;
    }
    if (sum >= x) {
        cout << l << endl;
        return 0;
    }
    cout << -1 << endl;
}