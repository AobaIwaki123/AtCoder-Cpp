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

ll ans = INF;
ll n,k;
vector<ll> a(33);

void saiki(ll x, ll A, ll pos){
    if(x == k){
        ll T = 0;
        ll I = 1000000000, Z = 5000000000;
        for ( ll j = 0; j < 10; j++){
            if (pos <= 0) break;
            T += pos / Z;
            T += pos % Z / I;
            pos = pos % Z % I;
            I = I / 10;
            Z = Z / 10; 
        }
        ans = min(ans, T);
        return;
    }
    ll last = 0;
    if (x >= 1) last = A + 1;
    for (ll i = last; i < min(n - k + x + 1, n); i++){
        ll b = A, POS = pos, X = x;
        b = i;
        POS += a[i];
        X++;
        saiki(X, b, POS);
    }
}
int _main(){
    cin >> n >> k;
    rep(i, n) cin >> a[i];
    ll t = 0;
    ll v = 0;
    ll y = 0;
    saiki(y, t, v);
    cout << ans << endl;
    return 0;
}