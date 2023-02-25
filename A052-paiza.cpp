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

int N,A,B;
int dp[2000010];

int main()
{
    cin >> N >> A >> B;
    for(int i = 0; i <= N; i++) dp[i]=1;
    dp[0] = 0;
    for(int i = 0; i <= N; i++){
        if(N-i < A && N-i < B){
            if(dp[i] == 0) dp[N] = 0;
            else continue;
        }
        if(N-i >= A && dp[i] == 0) dp[i+A]=0;
        if(N-i >= B && dp[i] == 0) dp[i+B]=0;
    }

    ll ans = 0;
    for(int i = 0; i <= N; i++) ans += dp[i];
    cout << ans << endl;
    return 0;
}