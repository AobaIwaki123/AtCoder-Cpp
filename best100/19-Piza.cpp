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
    ll d; cin >> d;
    ll N; cin >> N;
    ll M; cin >> M;
    vector<ll> D(N+1);
    reps(i, 1, N) cin >> D[i];
    D[0] = 0; D[N] = d;
    sort(all(D));
    vector<ll> K(M);
    rep(i, M) cin >> K[i];
    sort(all(K));
    ll ans = 0;
    rep(i, M){
        ll idx = lower_bound(all(D), K[i]) - D.begin();
        ll dist = min(abs(D[idx] - K[i]), abs(D[idx-1] - K[i]));
        ans += dist;
    }
    cout << ans << endl;
    return 0;
}