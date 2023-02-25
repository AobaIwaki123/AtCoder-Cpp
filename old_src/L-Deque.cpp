#include <bits/stdc++.h>
#define ALL(obj) begin(obj), end(obj)
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define rrep(i, n) reps(i, 1, n + 1)
const ll INF = 1e18;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

// 模範解答1
// int N;
// ll a[3010];
// ll dp[3010][3010];
// 
// int main()
// {
//     cin >> N;
//     rep(i,N) cin >> a[i];
//     rrep(i,N) dp[i][i] = a[i-1];
// 
//     rrep(j,N-1) rrep(i,N-1){
//         if(i+j <= N){
//             dp[i][i+j] = max(-dp[i+1][i+j] + a[i-1], -dp[i][i+j-1] + a[i+j-1]);
//         }
//     }
//     cout << dp[1][N] << endl;
//     return 0;
// }

// 模範解答2 メモ化再帰
int N;
vector<vector<ll>> dp;
vector<ll> a;

ll rec(int l = 0, int r = N){
    // 
    if(r == l) return 0;
    // dp[l][r]のアドレスを&retで受け取る
    ll &ret = dp[l][r];
    // メモ化再帰の部分
    if(ret != INF) return ret;
    // 先攻：最大化を目指す
    if((N-(r-l)) % 2 == 0){
        ret = max(a[l] + rec(l+1,r), rec(l,r-1) + a[r-1]);
    }
    // 後攻：最小化を目指す
    else{
        ret = min(-a[l] + rec(l+1,r), rec(l,r-1) - a[r-1]);
    }
    return ret;
}

int main(){
    cin >> N;
    a.assign(N,0);
    dp.assign(N+5, vector<ll>(N+5, INF));
    rep(i,N) cin >> a.at(i);
    cout << rec() << endl;
    return 0;
}