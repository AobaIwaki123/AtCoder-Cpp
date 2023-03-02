#include <bits/stdc++.h>
using namespace std; int _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll;
typedef pair<ll, ll> P;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define rrep(i, n) reps(i, 1, n + 1)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

// 答えを見た
// 考え方：工夫した全探索

int _main(){
    ll n; cin >> n;
    ll a,b,c; cin >> a >> b >> c;
    ll ans = 9999;
    rep(i,10000){
        rep(j,10000-i){
            if(n-i*a-j*b>=0 && (n - i*a - j*b)%c==0){
                ll k = (n - i*a - j*b)/c;
                chmin(ans , i+j+k);
            }
        }
    }
    cout << ans << endl;
    return 0;
}

// 以下、DPを用いたTLEのコード

// int _main()
// {
//     ll n; cin >> n;
//     ll a,b,c; cin >> a >> b >> c;
//     ll cnt = 10000;
//     vector<vector<bool>> dp(cnt, vector<bool>(n+1,0));
//     dp[0][0] = 1;
//     rrep(i,cnt-1){
//         rep(j,n+1){
//             dp[i][j] = dp[i][j] || dp[i-1][j];
//             if(j-a>=0) dp[i][j] = dp[i][j] || dp[i-1][j-a];
//             if(j-b>=0) dp[i][j] = dp[i][j] || dp[i-1][j-b];
//             if(j-c>=0) dp[i][j] = dp[i][j] || dp[i-1][j-c];
//             if(dp[i][n]) {
//                 // cout << dp[i][n] << endl;
//                 cout << i << endl;
//                 return 0;
//             }
//         }
//     }
//     return 0;
// }