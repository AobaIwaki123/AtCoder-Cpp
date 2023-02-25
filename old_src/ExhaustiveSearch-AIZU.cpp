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

ll n,q;
ll a[30],m[210];
bool dp[30][2010];

int _main()
{
    cin >> n;
    rep(i,n) cin >> a[i];
    cin >> q;
    rep(i,q) cin >> m[i];
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;
    rep(i,n){
        rep(j,2001){
            dp[i+1][j] |= dp[i][j];
            if(j-a[i]>=0)dp[i+1][j] |= dp[i][j-a[i]];
        }
    }
    rep(i,q){
        if(dp[n][m[i]])cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}