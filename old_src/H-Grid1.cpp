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

// int H,W,_;
// char a[1010][1010];
// vector<int> G[1010][1010];
// int dp[1010][1010];

// int dfs(int i, int j){
//     if(dp[i][j] > 0) return dp[i][j];
//     ll res = 0;
//     if(i == H-1 && j == W-1) {
//         // cout << i << ',' << j << " " << dp[i][j] << endl;
//         res = (res + 1)%(1000000000+7);
//         dp[i][j] = res;
//         return dp[i][j];
//     }
//     for(auto u : G[i][j]){
//         if(u == 1) res = (res + dfs(i+1,j))%(1000000000+7);
//         if(u == -1) res = (res + dfs(i, j+1))%(1000000000+7);
//     }
//     dp[i][j] = res;
//     // cout << i << ',' << j << " " << dp[i][j] << endl;
//     return dp[i][j];
// }

// int main()
// {
//     cin >> H >> W;
//     rep(i,H) rep(j,W) cin >> a[i][j];
//     rep(i,H) rep(j,W){
//         if(a[i+1][j] == '.') G[i][j].push_back(1);
//         else G[i][j].push_back(0);
//         if(a[i][j+1] == '.') G[i][j].push_back(-1);
//         else G[i][j].push_back(0);
//     }
//     // for(auto u : G[0][2]) cout << u << endl;
//     ll ans=0;
//     memset(dp, 0, sizeof(dp));
//     dfs(0,0);
//     // rep(i,H) rep(j,W) cout << dp[i][j] << (j == W-1 ? "\n" : " ");
//     cout << dp[0][0] << endl;
//     return 0;
// }
// 
// // 模範解答
const int MOD = 1000000007;
int H,W;
vector<string> a;
int dp[1100][1100]= {0};

void add(int &a, int b){
    a += b;
    if(a >= MOD) a -= MOD;
}

int main(){
    cin >> H >> W;
    a.resize(H);
    rep(i,H) cin >> a[i];
    dp[0][0] = 1;
    rep(i,H) rep(j,W){
        if(i+1 < H && a[i+1][j] == '.') add(dp[i+1][j], dp[i][j]);
        if(j+1 < W && a[i][j+1] == '.') add(dp[i][j+1], dp[i][j]);
    }
    cout << dp[H-1][W-1] << endl;
}