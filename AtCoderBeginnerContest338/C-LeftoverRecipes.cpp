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
    ll N;
    cin >> N;
    ll Q[20], A[20] ,B[20];
    rep(i, N) cin >> Q[i];
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> B[i];

    ll ans = 0;
    ll maxQ = 1;
    rep(i, N) chmax(maxQ, Q[i]);
    rep(x, maxQ + 1){
        ll y = INF;
        rep(i, N){
            if(Q[i] < A[i] * x) y = -INF;
            else if (B[i] > 0) y = min(y, (Q[i] - A[i] * x) / B[i]);
        }
        ans = max(ans, x + y);
    }
    cout << ans << endl;
    return 0;
}