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
    ll h, w, n;
    cin >> h >> w >> n;
    string t,s[505];
    cin >> t;
    rrep(i, h) cin >> s[i];

    ll ans = 0;
    rrep(i, h){
        rep(j, w){
            if(s[i][j] == '#') continue;
            ll I = i, J = j; bool ok = true;
            fore(c, t){
                if( c == 'L') J--;
                if( c == 'R') J++;
                if( c == 'U') I--;
                if( c == 'D') I++;
                if(s[I][J] == '#'){
                    ok = false;
                    break;
                }
            }
            if(ok) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}