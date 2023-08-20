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
    ll N, Y; cin >> N >> Y;
    ll a = -1; ll b = -1; ll c = -1;
    rep(i, N+1){
        rep(j, N+1){
            if(i + j > N) continue;
            ll k = N - i - j;
            ll price = i * 10000 + j * 5000 + k * 1000;
            if(price == Y){
                a = i; b = j; c = k;
            }
        }
    }
    cout << a << " " << b << " " << c << endl;
    return 0;
}