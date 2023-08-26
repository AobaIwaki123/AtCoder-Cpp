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
    int N;
    cin >> N;
    vector<int> X(N), Y(N), Z(N);
    rep(i, N) cin >> X[i] >> Y[i] >> Z[i];

    // 議席数zの合計値を計算する
    int z_sum = accumulate(all(Z), 0);
    // dpを初期化
    vector<ll> dp(z_sum + 1, INF);
    // 0議席を得るのに必要な鞍替えさせる人数
    dp[0] = 0;
    // 全ての選挙区について全探索
    rep(i, N){
        // i番目の選挙区の情報を取得
        int x = X[i], y = Y[i], z = Z[i];
        // i番目の選挙区の勝利に必要な人数を計算
        int w = max(0, (x + y + 1) / 2 - x);
        // 総議席数z_sumからzまで探索
        for(int j = z_sum; j >= z; j--){
            dp[j] = min(dp[j], dp[j - z] + w);
        }
    }

    ll ans = INF;
    // 選挙に勝てる議席数以上を得るのに必要な鞍替えさせる人数のうち、最小値を取得
    reps(j, z_sum / 2 + 1, z_sum + 1) ans = min(ans, dp[j]);
    cout << ans << endl;
    return 0;
}