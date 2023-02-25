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

// ACコードを参考にした
// DPかと思ったが、工夫した全探索で解くことができた
// この問題のキモは、3重ループを2重ループに削減するという
// 基本的な全探索手法を用いて解けることに気がつけることだと感じた
// y /= 1000もキモになるかと思っていたが、書いてみるとそんなことはなさそうだと感じた
// (ループ回数に寄与しないため)

int _main()
{
    ll n,y; cin >> n >> y;
    y /= 1000;
    for(ll i = 0; i <= n; i++){
        for(ll j = 0; j <= n-i; j++){
            ll k = n - i - j;
            if(10*i+5*j+k==y){
                cout << i << " " << j << " " << k << endl;
                return 0;
            }
        }
    }
    cout << -1 << " " << -1 << " " << -1 << endl;
    return 0;
}