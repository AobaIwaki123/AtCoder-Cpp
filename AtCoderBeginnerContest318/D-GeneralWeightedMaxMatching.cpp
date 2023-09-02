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



int _main()
{
    int n;
    cin >> n;
    vector d(n, vector(n, 0));

    rep(i, n){
        reps(j, i+1, n) cin >> d[i][j];
    }

    vector dp(1 << n, 0ll);

    rep(b, (1 << n) - 1){

        int l = -1;

        rep(i, n) if(!(b >> i & 1)){
            l = i;
            break;
        }

        rep(i, n) if(!(b >> i & 1)){
            int nb = b | (1 << l) | (1 << i);
            dp[nb] = max(dp[nb], dp[b] + d[l][i]);
        }
    }
    cout << dp.back() << endl;
    return 0;
}