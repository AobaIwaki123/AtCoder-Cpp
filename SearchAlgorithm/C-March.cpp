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
    ll a[10] = {};
    rep(i,N) {
        string s;
        cin >> s;
        if (s[0] == 'M') a[0]++;
        if (s[0] == 'A') a[1]++;
        if (s[0] == 'R') a[2]++;
        if (s[0] == 'C') a[3]++;
        if (s[0] == 'H') a[4]++;
    }

    ll ans = 0;
    reps(i, 0, 5) reps(j, i+1, 5) reps(k, j+1, 5) ans += a[i] * a[j] * a[k];
    cout << ans << endl;
    return 0;
}