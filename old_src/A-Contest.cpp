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

bool dp[110][10010];

int main()
{
    int N; cin >> N;
    int p[110]; rep(i,N) cin >> p[i];
    int M = 100;
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;
    rep(i,N){
        rep(j,N*M+1){
            dp[i+1][j] = dp[i][j];
            if(j >= p[i]) dp[i+1][j] |= dp[i][j-p[i]];
        }
    }
    int sum = 0;
    rep(j,N*M+1) sum += dp[N][j];
    cout << sum << endl;
    return 0;
}