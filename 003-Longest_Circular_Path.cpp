#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define rrep(i, n) reps(i, 1, n + 1)
const ll INF = 1LL << 60;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int N,A,B;
ll dp[100010];
vector<int> G[100010];

int wfs(ll v, ll cnt){
    if(dp[v] > 0) return 0;
    dp[v] = cnt;
    cnt++;
    for(auto u : G[v]){
        wfs(u,cnt);
    }
    return 0;
}

int main()
{
    cin >> N;
    rep(i,N-1){
        cin >> A >> B;
        G[A].push_back(B);
        G[B].push_back(A);
    }

    memset(dp,0,sizeof(dp));
    wfs(A,1);

    ll longest = 1;
    int V;

    rrep(i,N){
        if(dp[i] > longest){
            longest = dp[i];
            V = i;
        }
    }

    memset(dp,0,sizeof(dp));
    wfs(V,1);

    longest = 1;
    int W;

    rrep(i,N){
        if(dp[i] > longest){
            longest = dp[i];
            W = i;
        }
    }

    cout << dp[W] << endl;
    return 0;
}

// 模範解答
// ある点uから最も遠い点vを求め、点vから最も遠い点wを求めた時のv-w間の距離が木の直径となる。
// 求める答えは、木の直径+1となる。
// unsolved
// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// ll INF = 1LL << 60;
// using Graph = vector<vector<int>>;
// Graph g;
// vector<int> dist;
// pair<int, int> p = {1, 0};
// 
// void solv(int now) {
//     for (int x : g[now]) {
//         if (dist[x] != -1) continue;
//         dist[x] = dist[now] + 1;
//         if (dist[x] >= p.second) p = {x, dist[x]};
//         solv(x);
//     }
//     return;
// }
// 
// int main() {
//     int n;
//     cin >> n;
//     g.assign(n + 1, vector<int>());
//     for (int i = 1; i < n; i++) {
//         int a, b;
//         cin >> a >> b;
//         g[a].push_back(b);
//         g[b].push_back(a);
//     }
//     dist.assign(n + 1, -1);
//     dist[1] = 0;
//     solv(1);
//     int start = p.first;
//     p = {start, 0};
// 
//     dist.assign(n + 1, -1);
//     dist[start] = 0;
//     solv(start);
// 
//     cout << p.second + 1 << endl;
// }
