#include <bits/stdc++.h>
using namespace std; int _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll;
// typedef pair<ll, ll> P;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define rrep(i, n) reps(i, 1, n + 1)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

double P;
double func(double x){
    return 1 - P / pow(2, x / 1.5) * log(2) / 1.5;
}

double ans(double x){
    return x + P / pow(2, x / 1.5);
}

int _main()
{
    cout << fixed << setprecision(15);
    cin >> P;
    double l = 0, r = 1e18;
    double EPS = 1e-10;
    while(fabs(r - l) > EPS){
        double mid = (l + r) / 2;
        // cout << mid << endl;
        if(func(mid) > 0) r = mid;
        else l = mid;
    }
    cout << ans(l) << endl;
    return 0;
}