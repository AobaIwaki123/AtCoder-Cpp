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

// 通った場所を保持する構造体を定義する
struct State{
    bool used[7][7];
};

// 上、右、下、左を定義
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int dfs(int N, int px, int py, State S){
    // 現在地がゴールの場合1を返す
    if(px == N && py == N) return 1;
    // 通り数の合計値を初期化
    int sum = 0;
    // 移動方向を探索
    rep(i, 4){
        // 移動先情報を取得
        int sx = px + dx[i];
        int sy = py + dy[i];
        // 移動可能か判定
        if(sx < 0 || sy < 0 || sx > N || sy > N) continue;
        // 移動済みラベルが貼られていた場合スルー
        if(S.used[sx][sy] == true) continue;
        // 次の状態を定義
        State NextState = S; 
        // 移動先にラベルをはる
        NextState.used[sx][sy] = true;
        sum += dfs(N, sx, sy, NextState);
    }
    // 通り数をreturn
    return sum;
}
int _main()
{
    int N; cin >> N;
    State InitS;
    rep(i, N+1){
        rep(j, N+1){
            InitS.used[i][j] = false;
        }
    }
    InitS.used[0][0] = true;

    cout << dfs(N, 0, 0, InitS) << endl;
    return 0;
}
