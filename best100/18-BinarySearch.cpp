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
    ll N; cin >> N;
    vector<ll> S(N);
    rep(i, N) cin >> S[i];
    ll Q; cin >> Q;
    vector<ll> T(Q);
    rep(i, Q) cin >> T[i];
    sort(all(S)); sort(all(T));
    ll ans = 0;
    rep(i, Q){
        ll idx = lower_bound(all(S), T[i]) - S.begin();
        if(T[i] == S[idx]) ans++;
    }
    cout << ans << endl;
    return 0;
}