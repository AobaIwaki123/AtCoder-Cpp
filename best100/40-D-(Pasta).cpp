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

const ll MOD = 10000;

void add(ll&a, ll b){
    a = (a+b) % MOD;
}

int _main()
{
    int N, K;
    cin >> N >> K;
    vector<int> F(N, -1);
    while(K--){
        int a, b;
        cin >> a >> b;
        F[a-1] = b-1;
    }

    // 初期化
    ll dp[101][3][3] = {0}; 
    // 1日目に選べるパスタのパターンは、1
    dp[0][0][0] = 1;

    // 全ての日付について全探索
    rep(i, N) 
        // i-2日目のパスタの種類
        rep(a, 3) 
            // i-1日目のパスタの種類
            rep(b, 3){
                // パスタの選択パターン
                vector<int> cs = {0, 1, 2};
                // 事前にパスタが決まっていればそれで上書き
                if(F[i] >= 0) cs = {F[i]};
                // パスタの選択パターンを探索
                for(int c : cs){
                    // 2日目以降でa,b,cが同じ場合はスキップ
                    if(i >= 2 && a == b && b == c) continue;
                    add(dp[i+1][b][c], dp[i][a][b]);
                }
            }

    ll ans = 0;
    rep(a, 3) rep(b, 3) add(ans, dp[N][a][b]);
    cout << ans << endl;
    return 0;
}