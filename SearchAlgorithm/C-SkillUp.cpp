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
    ll N, M, X;
    cin >> N >> M >> X;
    ll C[20];
    ll A[20][20];
    rep(i, N){
        cin >> C[i];
        rep(j, M){
            cin >> A[i][j];
        }
    }
    ll ans = -1;
    // N冊の参考書についてbit全探索
    rep(msk, 1 << N){
        ll D[20] = {};
        ll price = 0;
        rep(i, N){
            // i冊目の参考書を購入する場合、合計金額と理解度を加算
            if (msk & (1 << i)){
                // 合計金額を加算
                price += C[i];
                // 理解度を加算
                rep(j, M){
                    D[j] += A[i][j];
                }
            }
        }
        // 全ての理解度が基準X以上か判定
        bool ok = true;
        rep(i, M) if (! (D[i] >= X)) ok = false;
        if (ok){
            if (ans == -1) ans = price;
            else chmin(ans, price);
        }
    }

    cout << ans << endl;
    return 0;
}
