/*
atcoder abc441 E - A < B substring
username peace10 == Kawase-Hiroki
*/

#include <bits/stdc++.h>
using namespace std;

class BIT {
public:
    BIT() = default;
    explicit BIT(size_t size)
        : m_bit(size + 1) {}

    explicit BIT(const std::vector<long long>& v)
        : BIT(v.size()) {
        for (int i = 0; i < static_cast<int>(v.size()); ++i) {
            add((i + 1), v[i]);
        }
    }

    long long sum(int r) const {
        long long ret = 0;

        for (; 0 < r; r -= (r & -r)) {
            ret += m_bit[r];
        }

        return ret;
    }

    long long sum(int l, int r) const {
        return (sum(r) - sum(l - 1));
    }

    void add(int i, long long value) {
        for (; i < static_cast<int>(m_bit.size()); i += (i & -i)) {
            m_bit[i] += value;
        }
    }

private:
    std::vector<long long> m_bit;
};

int main() {
    int n;
    string s;
    cin >> n >> s;

    vector<long long> d(n + 1, 0);

    for (int i = 0; i < n; i++) {
        d[i + 1] = d[i];
        if (s[i] == 'A')
            d[i + 1]++;
        if (s[i] == 'B')
            d[i + 1]--;
    }

    auto comp = d;
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());

    BIT bit(n + 1);
    long long ans = 0;
    for (int i = 0; i < n + 1; i++) {
        int idx = lower_bound(comp.begin(), comp.end(), d[i]) - comp.begin() + 1;
        ans += bit.sum(idx - 1);
        bit.add(idx, 1);
    }
    cout << ans << endl;
}