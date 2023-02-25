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

ll N;
ll a[100010];
ll b[100010];
ll c[100010];
ll dp[100010][3];

int main()
{
    cin >> N;
    rep(i,N) cin >> a[i] >> b[i] >> c[i];

    memset(dp, 0, sizeof(dp));

    dp[0][0] = a[0];
    dp[0][1] = b[0];
    dp[0][2] = c[0];

    for(int i = 1; i < N; i++){
        dp[i][0] = max({dp[i][0], dp[i-1][1]+a[i], dp[i-1][2]+a[i]}); // 0:a
        dp[i][1] = max({dp[i][1], dp[i-1][2]+b[i], dp[i-1][0]+b[i]}); // 1:b
        dp[i][2] = max({dp[i][2], dp[i-1][0]+c[i], dp[i-1][1]+c[i]}); // 2:c
        // cout << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << endl;
    }
    ll ans = max({dp[N-1][0], dp[N-1][1], dp[N-1][2]});
    cout << ans << endl;
    return 0;
}
