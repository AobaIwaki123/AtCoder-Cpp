#include <bits/stdc++.h>
using namespace std; int _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll;
typedef pair<ll, ll> P;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define rrep(i, n) reps(i, 1, n + 1)
#define fore(i,a) for(auto i:a)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

// 模範解答
// 考え方
// 1. パスグラフが満たすべき条件を考える
// 2. パスグラフであるためには、辺の本数がn-1本である必要がある。
// 3. パスグラフであるためには、次数が3以上の頂点が存在してはならない
// 4. この時点でグラフがパスグラフでないとすればそれは連結でない場合である。
// 5. 幅優先探索によって連結性を確かめる

int _main()
{
    // 変数の宣言
    ll n,m;
    cin >> n >> m;
    vector<vector<ll>> graph(n);
    // graphをindexの形で保持
    rep(i,m){
        ll u,v;
        cin >> u >> v;
        u--;v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    // グラフがパスグラフであるためには、辺の本数がn-1本である必要がある。
    if(m != n-1){
        cout << "No" << endl;
        return 0;
    }
    // グラフがパスグラフであるためには、次数が3以上の頂点が存在してはならない
    rep(i,n){
        if(graph[i].size() > 2){
            cout << "No" << endl;
            return 0;
        }
    }
    // この時点でグラフがパスグラフでない可能性はグラフが連結でない以外あり得ない
    // 従って、幅優先探索によりグラフの連結性を確かめる
    vector<bool> reach(n); 
    queue<ll> que;
    reach[0] = true; // 頂点0に訪問したことを記録
    que.push(0); // queに頂点0を格納
    // queが空でない間処理を行う
    while(not que.empty()){
        const ll u = que.front(); //queの最初の値を取り出す
        que.pop(); // queの最初の値を削除
        // 頂点uに繋がる頂点vを探索する
        fore(v,graph[u]){
            // 頂点vに訪れていなければ処理を行う
            if(not reach[v]){
                reach[v] = true; // 頂点vに訪問したことを記録
                que.push(v); // queに頂点vを格納
            }
        }
    }
    // 訪問していない頂点がないか判定する
    rep(i,n){
        if(!reach[i]){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}