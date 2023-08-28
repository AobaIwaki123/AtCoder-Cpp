#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define rrep(i, n) reps(i, 1, n + 1)

vector<vector<int> > G(110);
int ans[110][2];
bool seen[110];

int dfs(int from, int time_stamp){
    if(seen[from]) return time_stamp;
    seen[from] = true;
    time_stamp++;
    ans[from][0] = time_stamp;
    for(int to : G[from]){
        time_stamp = dfs(to, time_stamp);
    }
    time_stamp++;
    ans[from][1] = time_stamp;
    return time_stamp;
}
int main()
{
    ll N; cin >> N;
    rep(i, N){
        ll u, k; cin >> u >> k;
        seen[u] = false;
        rep(j, k){
            ll v; cin >> v;
            G[u].push_back(v);
        }
    }
    int time_stamp = 0;
    rrep(i, N){
        time_stamp = dfs(i, time_stamp);
    }
    rrep(i, N){
        cout << i << " " << ans[i][0] << " " << ans[i][1] << endl;
    }
    return 0;
}