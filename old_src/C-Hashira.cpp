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
int a[100010];
ll dp[100010];

int main()
{
    cin >> N;
    rrep(i,N) {
        cin >> a[i];
        dp[i] = INF;
    }
    dp[1] = 0;
    for(int i = 2; i <= N; i++){
        chmin(dp[i], dp[i-1] + abs(a[i] - a[i-1]));
        if(i-2>=1) chmin(dp[i], dp[i-2] + abs(a[i] - a[i-2]));
    }
    cout << dp[N] << endl;
    return 0;
}