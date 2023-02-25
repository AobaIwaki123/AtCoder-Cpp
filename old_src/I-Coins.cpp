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

int N;
vector<double> p;
double dp[3100][3100];

int main()
{
    cin >> N;
    p.resize(N);
    rep(i,N) cin >> p[i];
    dp[0][0] = 1.0;
    
    rep(i,N) rep(j,i+1){
        dp[i+1][j+1] += dp[i][j] * p[i];
        dp[i+1][j] += dp[i][j] * (1.0 - p[i]);
    }
    
    double res = 0.0;
    reps(j,N/2+1,N+1) res += dp[N][j];
    cout << fixed << setprecision(10) << res << endl;
    return 0;
}