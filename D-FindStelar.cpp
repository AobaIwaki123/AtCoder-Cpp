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

ll n,m;
ll mx[210],my[210],nx[1010],ny[1010];

bool check(ll x, ll y){
    rep(i,n){
        if(x==nx[i] && y==ny[i]) return true;
    }
    return false;
}
int _main()
{
    cin >> m;
    rep(i,m) cin >> mx[i] >> my[i];
    cin >> n;
    rep(i,n) cin >> nx[i] >> ny[i];
    rep(i,n){
        ll vx = nx[i]-mx[0]; ll vy = ny[i]-my[0];
        bool res = true;
        reps(j,1,m){
            if(!check(mx[j]+vx,my[j]+vy)){
                res = false;
                break;
            }
        }
        if(res){
            cout << vx << " " << vy << endl;
            return 0;
        }
    }
    return 0;
}