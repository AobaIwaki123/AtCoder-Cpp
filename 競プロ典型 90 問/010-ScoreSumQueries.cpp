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
    vector<vector<ll>> sum(2, vector<ll>(n,0));
    rep(i,n){
        ll c,p; cin >> c >> p;
        sum[0][i]=sum[0][i-1];
        sum[1][i]=sum[1][i-1];
        if(c==1){
            sum[0][i]+=p;
        }
        else{
            sum[1][i]+=p;
        }
    }
    ll q; cin >> q;
    ll ans[2];
    rep(i,q){
        ll l,r; cin >> l >> r;
        if(l==0){
            ans[0] = sum[0][r-1];
            ans[1] = sum[1][r-1];
        }
        else{
            ans[0] = sum[0][r-1] - sum[0][l-2];
            ans[1] = sum[1][r-1] - sum[1][l-2];
        }
        cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}