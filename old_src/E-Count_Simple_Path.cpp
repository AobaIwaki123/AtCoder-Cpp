// 模範解答
#include <iostream>
#include <vector>
using namespace std;

// 既に訪問した頂点の情報を一時的にvisに格納し、その頂点からのびるすべての頂点を探索し終えたらvisをfalseにすることで
// 別頂点からの複数回の訪問を実現する。ansは全体で統一的に管理し、limitを超えた時点で計算を終了する。
int calc(int N, vector<vector<int>> g) {
    int ans = 0, limit = 1000000;
    vector<int> vis(N);
    auto dfs = [&](auto rc, int c) -> void {
        if (ans == limit) return;
        ans++;
        vis[c] = true;
        for (auto& d : g[c]) {
            if (vis[d]) continue;
            rc(rc, d);
        }
        vis[c] = false;
    };
    dfs(dfs, 0);
    return ans;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> g(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cout << calc(N, g) << "\n";
}
