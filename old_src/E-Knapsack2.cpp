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
ll w[110],v[110];

int main()
{
    cin >> N >> W;
    rrep(i,N) cin >> w[i] >> v[i];

    vector dp(N+1, vector<ll>(W+1, 0));

    dp[0][w[0]] = v[0];

    rrep(i,N){
        rrep(j,W){
            chmax(dp[i][j], dp[i-1][j]);
            if(j>=w[i]) chmax(dp[i][j], dp[i-1][j-w[i]]+v[i]);
        }
    }

    cout << dp[N][W] << endl;
    return 0;
}

// 模範解答
const int MAX_N = 110;
const int MAX_V = 100100;

int N;
ll W, weight[MAX_N], value[MAX_N];

ll dp[MAX_N][MAX_V];

int main(){
    cin >> N >> W;
    rep(i,N) cin >> weight[i] >> value[i];
    // initialize
    rep(i,MAX_N) rep(j,MAX_V) dp[i][j] = INF;
    // initial condition
    dp[0][0] = 0;
    rep(i,N){
        rep(sum_v,MAX_V){
            if(sum_v - value[i] >= 0) chmin(dp[i+1][sum_v], dp[i][sum_v-value[i]] + weight[i]);
            chmin(dp[i+1][sum_v], dp[i][sum_v]);
        }
    }
    ll res = 0;
    rep(sum_v,MAX_V){
        if(dp[N][sum_v] <= W) res = sum_v;
    }
    cout << res << endl;
    return 0;
}
