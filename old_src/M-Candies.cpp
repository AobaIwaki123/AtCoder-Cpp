#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define rrep(i, n) reps(i, 1, n + 1)
const ll INF = 1LL << 60;
const ll MOD = 1e9+7;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

// 模範解答1
// ll dp[110][100010];
// ll a[100010];
// 
// ll solve(int i, int j){
//     if(j == 0) return 1;
//     if(j < 0) return 0;
//     if(i == -1) return 0;
//     if(dp[i][j] != -1) return dp[i][j];
// 
//     return dp[i][j] = ((solve(i-1,j) + solve(i,j-1)) % MOD - solve(i-1,j-a[i]-1) + MOD) % MOD;
// }
// int main(){
//     int n,k; cin >> n >> k;
//     rep(i,n) cin >> a[i];
//     for(int i = 0; i <= n; i++) for(int j = 0; j <= k; j++){
//         dp[i][j] = -1;
//     }
//     cout << solve(n-1,k) << endl;
//     return 0;
// }

// 模範解答2
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
ll dp[102][100005];

int fun(vector<ll>& a, ll n, ll k){
    // 初期化：jがa[1](一人目が受け取れる飴の個数)より大きいならば1を入れる。それ以外は、1。
    // 言い換えると、一人目の場合、与えられた個数kを受け取れるなら1通りの与えかた、それ以外なら与える方法はないということを示す。
    rep(j,k+1) dp[1][j] = (j > a[1]) ? 0 : 1;

    reps(i,2,n+1){
        reps(j,0,k+1){
            // j=0(iの更新後、最初の１回だけ)特別な処理を行う。
            if(j == 0){
                // 直前の値(i-1)の値を引き継ぎ、MODをとる
                dp[i][j] = dp[i-1][j];
                dp[i][j] = (MOD + dp[i][j]) % MOD;
            }
            else{
                // dp[i][j]の値は、人数が一人少ない時の値と与える飴が一つ少ない時の値の和から
                // 人数が一人少なく、飴が1+a[i]個少ない時の値を引いた値で計算される。
                dp[i][j] = dp[i-1][j] + dp[i][j-1] - ((j-1-a[i] >= 0) ? dp[i-1][j-1-a[i]] : 0);
                dp[i][j] = (MOD + dp[i][j]) % MOD;
            }
        }
    }
    return dp[n][k];
}

int main(){
    fast_io;

    ll n,k;
    cin >> n >> k;
    
    vector<ll> a(n+1);
    rrep(i,n) cin >> a[i];

    cout << fun(a,n,k) << endl;
    return 0;
}