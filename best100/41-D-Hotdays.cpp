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
    ll D, N; cin >> D >> N;
    ll T[210];
    rep(i, D) cin >> T[i];
    ll A[210], B[210], C[210];
    rep(i, N) cin >> A[i] >> B[i]>> C[i];

    // i日目にj番目の服が着られるかを判定して保存
    bool suit[210][210];
    rep(i, D) rep(j, N){
        suit[i][j] = (A[j] <= T[i] && T[i] <= B[j]);
    }

    // 2次元dp配列を初期化
    ll dp[210][210];
    // i日目にj番目の服を着た時のスコアを保存
    rep(i, D) rep(j, N){
        dp[i][j] = -1;
    }   

    // 0日目にj番目の服を着た時のスコアを保存
    rep(j, N) if(suit[0][j]){
        dp[0][j] = 0;
    }

    // 1日目以降のdp配列を保存
    rep(i, D-1) 
        // j番目の服を着た場合のスコアを計算
        rep(j, N) 
            // 前日のスコアが存在するなら処理を行う
            if(dp[i][j] >= 0){
                // 服を探索
                rep(k, N) 
                    // i+1日目にk番目の服を着られるか判定
                    if(suit[i + 1][k]){
                        // i日目のスコアに現在のスコアを足した値が上回るなら更新
                        if(dp[i + 1][k] < dp[i][j] + abs(C[j] - C[k])) {
                            dp[i + 1][k] = dp[i][j] + abs(C[j] - C[k]);
                        }
                    }
    }

    // 回答を初期化
    ll ans = -1;
    // 最終日にj番目の服を着た時の回答の最大値を保存
    rep(j, N){
        if(ans < dp[D - 1][j]){
            ans = dp[D - 1][j];
        }
    }
    cout << ans << endl;
    return 0;
}