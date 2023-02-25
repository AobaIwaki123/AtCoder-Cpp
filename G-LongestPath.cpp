#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define rrep(i, n) reps(i, 1, n + 1)
const ll INF = 1LL << 60;

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

ll N,M;
// ll x[100010];
// ll y[100010];
ll x,y,_;
// vector G(100010, vector<ll>(100010,0));
ll dp[100010];
vector<int> G[100010];

// dps
int dfs(ll v){
    // cout << v << " ";
    if(dp[v]>0) {
        // cout << endl << "node" << v << " dist:" << dp[v] << endl;
        return dp[v];
    }
    ll res = 1;
    ll _res;
    for(auto u : G[v]){
        _res = dfs(u)+1;
        chmax(res,_res);
    }
    dp[v] = res;
    // cout << endl << "node" << v << " dist:" << res << endl;
    return res;
}

int main()
{
    cin >> N >> M;
    rep(i,M){
        cin >> x >> y;
        G[x].push_back(y);
    }
    // for(auto u : G[3]) cout << u << endl;
    // memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= N; i++){
        _ = dfs(i);
    }
    ll ans = 0;
    for(int i = 1; i <= N; i++){
        if(dp[i]>ans) ans = dp[i]-1;
    }
    // cout << "ans:" << ans << endl;
    cout << ans << endl;
    return 0;
}