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

// 考え方
// 1. 任意の2点を選ぶ。O(N^2)
// 2. 任意2点が正方形の一部である時のその他の2点を計算する。O(2)
// 3. 正方形が存在する時にその面積を計算する。O(1)

ll n;
ll a[3010],b[3010];

bool check(ll x, ll y){
    rep(i,n){
        if(x==a[i] && y==b[i]) return true;
    }
    return false;
}

int _main()
{
    cin >> n;
    rep(i,n){
        cin >> a[i] >> b[i];
    }
    ll ans = 0;
    rep(i,n){
        ll x1 = a[i]; ll y1 = b[i];
        reps(j,i+1,n){
            ll x2 = a[j]; ll y2 = b[j];
            ll vx = x2 - x1; ll vy = y2 - y1;
            if(check(x1-vy,y1+vx) && check(x2-vy,y2+vx)){
                chmax(ans, (ll)pow(vx,2)+(ll)pow(vy,2));
            }
            if(check(x1+vy,y1-vx) && check(x2+vy,y2-vx)){
                chmax(ans, (ll)pow(vx,2)+(ll)pow(vy,2));
            }
        }
    }
    cout << ans << endl;
    return 0;
}