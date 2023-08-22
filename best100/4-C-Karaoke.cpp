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
    ll N, M; cin >> N >> M;
    ll ans = 0;
    ll A[110][110];
    rep(i, N) rep(j, M) cin >> A[i][j];
    for(ll i = 0; i < M; i++){
        for(ll j = i+1; j < M; j++){
            ll point_sum = 0;
            rep(k, N){
                point_sum += max(A[k][i], A[k][j]);
            }
            chmax(ans, point_sum);
        }
    }
    cout << ans << endl;
    return 0;
}