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
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    ll q; cin >> q;
    vector<ll> b(q);
    rep(i,q) cin >> b[i];

    sort(all(a)); // O(NlogN)

    // rep(i,n) cout << a[i] << " ";
    rep(i,q){
        ll id = lower_bound(a.begin(), a.end(), b[i]) - a.begin();
        // cout << id << " ";
        if(id==0){
            cout << abs(b[i]-a[id]) << endl;
        }
        else if(id>0){
            cout << min(abs(b[i]-a[id]), abs(b[i]-a[id-1])) << endl;
        }
    }
    return 0;
}