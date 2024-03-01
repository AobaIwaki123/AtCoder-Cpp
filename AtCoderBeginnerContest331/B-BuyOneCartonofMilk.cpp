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
    ll N, S, M, L;
    cin >> N >> S >> M >> L;
    ll ans = INF;
    rep(i, 100/6 + 1){
        rep(j, 100/8 + 1){
            rep(k, 100/12 + 1){
                if(i * 6 + j * 8 + k * 12 >= N) chmin(ans, i*S + j*M + k*L);
            }
        }
    }
    cout << ans << endl;
    return 0;
}