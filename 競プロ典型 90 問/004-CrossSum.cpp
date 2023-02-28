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
    ll h,w; cin >> h >> w;
    vector<vector<ll>> a(h, vector<ll>(w));
    vector<ll> row(h);
    vector<ll> col(w,0);
    rep(i,h){
        ll sum = 0;
        rep(j,w){ 
            cin >> a[i][j];
            col[j] += a[i][j];
            sum += a[i][j]; 
        }
        row[i] = sum;
    }

    // rep(i,h) cout << row[i] << (i==h-1 ? "\n" : " ");
    // rep(i,w) cout << col[i] << (i==w-1 ? "\n" : " ");
    vector<vector<ll>> ans(h, vector<ll>(w));
    rep(i,h)rep(j,w){
        ans[i][j] = row[i] + col[j] - a[i][j];
        cout << ans[i][j] << (j==w-1 ? "\n" : " ");
    }
    
    return 0;
}