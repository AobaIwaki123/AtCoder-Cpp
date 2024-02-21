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

// 参考 : https://atcoder.jp/contests/joi2015yo/submissions/50475197

int _main()
{
    ll N, M;
    cin >> N >> M;
    vector<vector<ll>> dp(N+1, vector<ll> (M+1, 0));
    vector<ll> D(N), C(M);
    rep(i, N) cin >> D[i];
    rep(j, M) cin >> C[j];
    rrep(i, N) rrep(j, M){
        if(i > j) continue;
        if(i == j){
            dp[i][j] = (ll)D[i-1] * C[i-1] + dp[i-1][j-1];
            continue;
        }
        dp[i][j] = min(dp[i][j-1], (ll)D[i-1] * C[j-1] + dp[i-1][j-1]);
    }
    cout << dp[N][M] << endl;
    return 0;
}