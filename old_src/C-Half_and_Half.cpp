#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define rrep(i, n) reps(i, 1, n + 1)
const ll INF = 1LL << 60;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int A,B,C,X,Y;

int main()
{
    cin >> A >> B >> C >> X >> Y;
    ll ans = A*X+B*Y;
    ll price = ans;
    while(X>0 || Y>0){
        X--;Y--;
        if(X>=0 && Y>=0) price = price - A - B + 2*C;
        else if(X>=0 && Y<0) price = price - A + 2*C;
        else if(X<0 && Y>=0) price = price - B + 2*C;
        chmin(ans,price);
    }
    cout << ans << endl;
    return 0;
}