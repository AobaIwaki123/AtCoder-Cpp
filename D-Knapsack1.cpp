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

ll N,W;
ll w[110];
ll v[110];
ll dp[110][100010];

int main()
{
    cin >> N >> W;
    for(int i = 1; i <= N; i++) cin >> w[i] >> v[i];

    memset(dp, 0, sizeof(dp));
    
    dp[0][w[0]] =  v[0];

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= W; j++){
            dp[i][j] = max({dp[i][j], dp[i-1][j]});
            if(w[i]<=j) dp[i][j] = max(dp[i][j], dp[i-1][j-w[i]]+v[i]);
            // cout << dp[i][j] << (j == W ? "\n" : " ");
        }
    }
    cout << dp[N][W] << endl;
    return 0;
}
