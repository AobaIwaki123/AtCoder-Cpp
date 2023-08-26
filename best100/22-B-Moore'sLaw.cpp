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

double a;
// 計算時間を返す関数
double func(double x){
    return x + a / pow(2, x / 1.5);
}

int _main()
{
    cout << fixed << setprecision(15);
    cin >> a;

    double L = 0;
    double R = 1e9;
    // 三分探索を行う
    for(int i = 0; i < 500; i++){
        double c1 = (L * 2 + R) / 3;
        double c2 = (L + 2 * R) / 3;
        // 計算時間の最小値を探索
        if (func(c1) > func(c2)) L = c1;
        else R = c2;
    }
    cout << func(R) << endl;
    return 0;
}
