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
const double EPS = 1e-8,PI = 2 * acos(0.0);

long double a, b, x;

void input(){
    cin >> a >> b >> x;
}

// a,b と角度thetaが与えられた時に入れられる水の量
long double f(long double a, long double b, long double theta){
    // 90度より大きい場合は水は残らない
    if(theta > PI / 2.0 - EPS){
        return 0.0;
    }
    long double ret;
    // おそらく台形パターン
    if(a * tan(theta) <= b){
        // 全体積から空白部分を除く
        ret = a * a * b - a * a * a * tan(theta) / 2.0;
    } else { // おそらく三角柱パターン
        // 三角柱の面積を計算する
        ret = b * b / tan(theta) * a / 2.0;
    }
    return ret;
}

void solve(){
    input();
    long double ok = PI / 2.0;
    long double ng = 0.0;
    // 二分法で探索
    for(int _ = 1; _ <= 100000; _++){
        long double mid = (ok + ng) / 2.0;
        if(f(a, b, mid) < x) ok = mid;
        else ng = mid;
    }
    cout << fixed << setprecision(10) << ok / PI * 180 << endl;
    return;
}
int _main(){
    solve();
    return 0;
}
// int _main()
// {
//     cin >> A >> B >> X;
// 
//     // 全体積の半分を計算
//     double half = A * A * B / 2;
//     double ans;
// 
//     // 水の体積が半分より大きいなら台形型で溢れ、小さいなら三角錐型で溢れる
//     if(X < half) ans = atan(A * B * B / (2.0 * X));
//     else ans = atan((2.0 * B - 2.0 * X / (A * A)) / A);
// 
//     ans = ans / PI * 180;
// 
//     printf("%.10f\n", ans);
// 
//     return 0;
// }