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
    ll N, K; cin >> N >> K;
    ll A[20];
    rep(i, N) cin >> A[i];
    ll ans = INF;
    rep(msk, 1 << N){
        if(__builtin_popcountll(msk) < K) continue;
        ll left_max = 0;
        ll price = 0;
        rep(i, N){
            ll h;
            if(msk & (1 << i)){
                if(A[i] < left_max + 1){
                    price += left_max + 1 - A[i];
                    h = left_max + 1;
                } else {
                    h = A[i];
                }
            } else {
                h = A[i];
            }
            chmax(left_max, h);
        }
        chmin(ans, price);
    }
    cout << ans << endl;
    return 0;
}