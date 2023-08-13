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
#define iINF (int)1<<30 //int

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }



int _main()
{
    // 1 <= N <= 100
    ll N;
    // 0 <= x, y <= 100, 0 <= h <= 1e9
    ll X[200], Y[200], H[200];
    cin >> N;
    rep(i, N) cin >> X[i] >> Y[i] >> H[i];
    // 高さHを格納する変数?
    ll min;
    // 答えのCx,Cyの範囲が[1,100]なのでそれを全探索する
    for (int i = 0; i <= 100; i++){
        for (int j = 0; j <= 100; j++){
            // 中心座標を仮定した後、推定高さminを初期化
            min = INF;
            rep(k,N) chmin(min, H[k] + abs(i-X[k]) + abs(j-Y[k]));
            bool ok = true;
            // 推定高さminが高さHの定義と矛盾しなければOK
            rep(k,N) if(H[k] != max((ll)0, min - abs(i-X[k]) - abs(j-Y[k]))) ok = false;
            if(ok){
                cout << i << " " << j << " " << min << endl;
                return 0;
            }
        }   

    }
    return 0;
}