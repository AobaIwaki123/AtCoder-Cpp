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
    bool M[110][110];
    rep(i, 110) rep(j, 110) M[i][j] = false;
    rep(i, N){
        ll a,b,c,d;
        cin >> a >> b >> c >> d;
        reps(x, a, b){
            reps(y, c, d){
                M[y][x] = true;
            }
        }
    }
    ll cnt = 0;
    rep(i, 110) rep(j, 110) if(M[i][j]) cnt++;
    cout << cnt << endl;
    return 0;
}