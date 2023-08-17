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

int N, M, Q, a[50], b[50], c[50], d[50];
int ans = 0;
int A[10];

// dfsを使って数列Aの全探索を行う
void dfs(int cu = 0, 
        int lst = 1 // Aに入力する最小値
        ){
    // Aの長さがNの場合処理を行う
    if (cu == N){
        rep(i, N) cout << A[i] << " ";
        cout << endl;
        // 合計を格納する変数
        int tot = 0;
        // Aのスコアを求める
        rep(i, Q) if (A[b[i]] - A[a[i]] == c[i]) tot += d[i];
        chmax(ans, tot);
        return;
    }
    // 再帰的にAを構成?
    // 最小値lstから最大値Mまでループ
    reps(nxt, lst, M+1){
        // インデックスcuにnxtを代入
        A[cu] = nxt;
        // lstをnxtで更新して、次のdfsを行う
        // この広義単調増加の制約から現実的な計算量で計算することができる
        dfs(cu + 1, nxt);
    }
}

int _main()
{
    cin >> N >> M >> Q;
    rep(i, Q){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        a[i]--; b[i]--;
    }

    dfs();
    cout << ans << endl;
    
    return 0;
}
