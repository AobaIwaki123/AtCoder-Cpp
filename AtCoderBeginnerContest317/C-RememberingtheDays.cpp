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

struct Edge {
    ll to;     // 辺の行き先
    ll weight; // 辺の重み
    Edge(ll t, ll w) : to(t), weight(w) { }
};
using Graph = vector<vector<Edge>>;

// 深さ優先探索
bool seen[20];
ll ans = 0;
// ll start = -1;
void dfs(const Graph &G, ll v, ll dist) {
    seen[v] = true; // v を訪問済にする

    // v から行ける各頂点 next_v について
    for (auto edge : G[v]) { 
        if (seen[edge.to]) continue; // edge.to が探索済だったらスルー
        // cout << "from " << v + 1 << " ";
        // cout << "to " << edge.to + 1 << endl;
        dfs(G, edge.to, dist + edge.weight); // 再帰的に探索
        seen[edge.to] = false;
    }
    if(dist > ans){
        ans = dist;
    }
}

int _main()
{
    ll N, M; cin >> N >> M;
    Graph G(N);
    rep(i, M){
        ll a, b, c; cin >> a >> b >> c;
        a--; b--;
        G[a].push_back(Edge(b, c));
        G[b].push_back(Edge(a, c));
    }
    rep(i, N){
        rep(i, N) seen[i] = false;
        dfs(G, i, 0);

    }
    cout << ans << endl;
    return 0;
}