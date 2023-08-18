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
const static long long NIL = -1;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }



int _main()
{
    int W, H;
    cin >> W >> H;
    // 与えられる情報よりも一回り大きい領域を確保する
    int h = H + 2;
    int w = W + 2;
    vector<vector<int>> fi(h, vector<int>(w,0));
    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++){
            cin >> fi[i][j];
        }
    }
    // xの偶奇によって処理を分ける
    int dx[2][6] = {
        {1, 0, -1, 0, 1, -1}, // even
        {1, 0, -1, 0, 1, -1} // odd
    };
    int dy[2][6] = {
        {0, 1, 0, -1, -1, -1}, // even
        {0, 1, 0, -1, 1, 1} // odd
    };
    // int dx[2][6] = {
    //     {0, 1, 1, 0, -1, -1}, // even
    //     {0, 1, 1, 0, -1, -1} // odd
    // };
    // int dy[2][6] = {
    //     {1, 0, -1, -1, -1, 0}, // even
    //     {1, 0, -1, -1, -1, 0} // odd
    // };
    // queueを定義
    queue<pair<int, int>> q;
    // 
    q.emplace(0, 0);
    // queueが空になるまでBFS的に全探索
    while(!q.empty()){
        // queueの最初の要素を取り出す
        pair<int, int> current = q.front();
        // queueの最初の要素を削除
        q.pop();
        // 現在の座標を取得
        int cx = current.first;
        int cy = current.second;
        // 6方向に移動できるか判定
        for(int d = 0; d < 6; d++){
            // 移動先の座標を取得
            int nx = cx + dx[cx % 2][d];
            int ny = cy + dy[cx % 2][d];
            // 移動可能領域か判定
            if(nx < 0 || nx >= h || ny < 0 || ny >= w)continue;
            // 建物か判定
            if(fi[nx][ny] == 1)continue;
            // 訪問済み領域か判定
            if(fi[nx][ny] == NIL)continue;
            // 訪問済み領域をマークする
            fi[nx][ny] = NIL;
            // 次の座標をqueueに追加
            q.emplace(nx, ny);
        }
    }
    int result = 0;
    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++){
            // 訪問済み領域か判定
            if(fi[i][j] == NIL)continue;
            // 移動可能方向を探索
            for(int d = 0; d < 6; d++){
                int nx = i + dx[i % 2][d];
                int ny = j + dy[i % 2][d];
                // 移動可能領域が塗り潰し済みであれば加算
                if(fi[nx][ny] == NIL){
                    result++;
                }
            }
        }
    }
    cout << result << endl;
    return 0;
}