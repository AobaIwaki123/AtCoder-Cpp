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
    ll A, B, C, X, Y;
    cin >> A >> B >>C >> X >> Y;
    ll ans = A*X + B*Y;
    ll Z = 0;
    while(!(X < 0 && Y < 0)){
        X--; Y--; Z+=2;
        ll price;
        if(X<0 && Y<0) price = C*Z;
        else if(X<0) price = B*Y + C*Z;
        else if(Y<0) price = A*X + C*Z;
        else price = A*X + B*Y + C*Z;
        chmin(ans , price);
    }
    cout << ans << endl;
    return 0;
}