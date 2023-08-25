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

bool a[12][12], choosed[12];

int _main()
{
    int n,m;
    cin >> n >> m;
    while(m--){
        int x, y;
        cin >> x >> y;
        --x; --y;
        a[x][y] = a[y][x] = 1;
    }
    int ans = 0;
    // マスク
    for(int S = 1; S < (1 << n) ; ++S){
        // カウント
        int cnt = 0;
        // 初期化
        for(int i = 0; i < n; i++) choosed[i] = 0;
        // マスクがかけられているところを選び、選んだ個数をカウント
        for(int i = n - 1; i >= 0; --i) if(S>>i & 1) choosed[i] = true, ++cnt;
        // 初期化
        bool ok = true;
        // クリーク確認
        for(int i = 0; i < n; ++i){
            // 選ばれていなければ無視
            if(!choosed[i]){continue;}
            // 注目するノードiが接続しているかどうか全てのノードについて探索
            for(int j = i + 1; j < n; j++){
                // 選ばれていなければ無視
                if(!choosed[j]){continue;}
                // 選ばれているのに、結ばれていなければクリークでない
                if(!a[i][j]){
                    ok = false;
                    break;
                }
            }
        }
        // 最も大きいカウントを保存
        if(ok) ans = max(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}