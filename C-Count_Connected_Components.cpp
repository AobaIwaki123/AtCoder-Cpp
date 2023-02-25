#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define rrep(i, n) reps(i, 1, n + 1)
const ll INF = 1LL << 60;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int N,M,u,v;
int dp[110];
// vector<int> G[110];
vector<int> G[100010];


int wfs(ll v, ll cnt){
    if(dp[v] > 0) return 0;
    dp[v] = cnt;
    cnt++;
    for(auto u : G[v]){
        wfs(u,cnt);
    }
    return 0;
}

int main()
{
    cin >> N >> M;
    rep(i,M){
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    memset(dp,0,sizeof(dp));
    rrep(i,N){
        wfs(i, 1);
    }
    // rrep(i,N){
    //     cout << dp[i] << endl;
    // }
    ll ans = 0;
    rrep(i,N){
        if(dp[i] == 1) ans++;
    }
    cout << ans << endl;

    return 0;
}