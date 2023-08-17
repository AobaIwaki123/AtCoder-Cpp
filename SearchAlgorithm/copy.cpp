#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << ": " << x << endl;

#define int long long


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int x;
    cin >> x;

    vector<vector<int>> a(n, vector<int>(m));
    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }


    int ans = INT_MAX;
    for (int mask = 0; mask < (1 << n); ++mask) {
        int sum = 0;
        vector<int> res(m);
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                sum += c[i];
                for (int j = 0; j < m; ++j) {
                    res[j] += a[i][j];
                }
            }
        }
        if (*min_element(res.begin(), res.end()) >= x) {
            ans = min(ans, sum);
        }
    }

    if (ans != INT_MAX) {
        cout << ans << '\n';
    } else {
        cout << "-1\n";
    }
    
    return 0;
}

