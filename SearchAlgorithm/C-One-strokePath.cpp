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
    ll N, M; cin >> N >> M;
    vector<ll> G[10];
    rep(i, M){
        ll a, b; cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<ll> P(N);
    rep(i, N) P[i] = i+1;
    ll ans = 0;

    // パスを順列全探索
    do {
        // 条件を満たしているか判定する変数
        bool ok = false;
        // 1から始まるパスの場合、処理を開始
        if (P[0] == 1){
            for(ll i=0; i < N-1; i++) {
                // ノードP[i]がP[i+1]と接続しているかチェック
                ll u = P[i];
                ll v = P[i+1];
                bool check = false;
                for(auto value:G[u]){
                    if(value == v) check = true;
                }
                // もし接続していなければ、条件を満たさない
                if (check) {ok = true;
                } else {
                    ok = false; 
                    break;
                }
            }
        }
        // 条件を満たしていれば加算
        if (ok) {
            // rep(i, N) cout << P[i] << " ";
            // cout << endl;
            ans++;
        }
    } while (next_permutation(all(P)));

    cout << ans << endl;
    return 0;
}
