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

int N,M,A;
int a[100010];
ll dp[100010];

int main()
{
    cin >> N >> M;
    memset(a,0,sizeof(a));
    rrep(i,M) {
        cin >> A;
        a[A] = 1;
    }
    memset(dp,0,sizeof(dp));
    dp[0] = 1;

    for(int i = 1; i <= N; i++){
        // cout << a[i] << " ";
        if(a[i] == 1) continue;
        if(a[i-1] == 1){
            if(a[i-2] == 1){
                cout << 0 << endl;
                return 0;
            }
            dp[i] = dp[i-2];
            continue;
        }
        if(a[i-2] == 1){
            dp[i] = dp[i-1];
            continue;
        }
        dp[i] = dp[i-1];
        if(i-2>=0) dp[i] += dp[i-2];
        dp[i] %= MOD;
    }
    // cout << endl;
    // rep(i,N+1) cout << dp[i] << " ";
    cout << dp[N] << endl;
    return 0;
}