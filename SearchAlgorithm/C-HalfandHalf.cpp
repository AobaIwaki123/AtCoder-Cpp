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
    // 1 <= A, B, C <= 5000
    ll A, B, C;
    // 1 <= X, Y <= 1e5
    ll X, Y;
    cin >> A >> B >> C >> X >> Y;
    ll ans = INF;

    ll maxC;
    if (X > Y) maxC = X;
    else maxC = Y;

    for (int i = 0; i <= maxC; i++){
        ll Anum, Bnum;
        if(X-i > 0) Anum = X-i; else Anum = 0;
        if(Y-i > 0) Bnum = Y-i; else Bnum = 0;
        ll price = A*Anum + B*Bnum + 2*C*i;
        if (price < ans) ans = price;
    }
    cout << ans << endl;
    return 0;
}
