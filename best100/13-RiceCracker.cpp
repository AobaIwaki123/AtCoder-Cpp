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

bool A[20][11000];

int _main()
{
    ll R, C;
    cin >> R >> C;
    rep(i, R) rep(j, C) cin >> A[i][j];
    ll ans = 0;
    rep(msk, 1 << R){
        bool B[20][11000];
        // cout << ans << endl;
        rep(i, R){
            if(msk & (1 << i)){
                rep(j, C) B[i][j] = not A[i][j];
            }else{
                rep(j, C) B[i][j] = A[i][j];
            }
        }
        // rep(i, R) {
        //     rep(j, C) cout << B[i][j] << " ";
        //     cout << endl;
        // }
        ll sum = 0;
        rep(j, C){
            ll cnt = 0;
            rep(i, R){
                cnt += B[i][j];
            }
            sum += max(R-cnt, cnt);
        }
        chmax(ans, sum);
    }
    cout << ans << endl;
    return 0;
}