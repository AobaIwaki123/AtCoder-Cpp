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
    ll A[210000];
    rep(i, N) cin >> A[i+1];
    A[0] = 0;
    A[N+1] = 0;
    ll m1[210000], m2[210000];
    m1[0] = min(A[0], A[1] - 1);
    m2[N-1] = A[N+1] + N + 1;

    reps(i, 1, N) m1[i] = min(m1[i-1], A[i+1] - i-1);
    for(ll i = N-2; i>=0; i--) m2[i] = min(m2[i+1], A[i+2] + i + 2);

    ll ans = 0;
    rep(i, N) ans = max(ans, min(m1[i] + i + 1, m2[i] - i - 1));

    cout << ans << endl;
    return 0;   
}