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

ll N, M, ans;
bool G[100][100];
bool seen[100][100];

void dfs(ll n, ll m, ll cnt = 1){
    if(seen[n][m]) return;
    seen[n][m] = true;
    if(n+1 < N) if(G[n+1][m]) dfs(n+1, m, cnt+1);
    if(m+1 < M) if(G[n][m+1]) dfs(n, m+1, cnt+1);
    if(n-1 >= 0) if(G[n-1][m]) dfs(n-1, m, cnt+1);
    if(m-1 >= 0) if(G[n][m-1]) dfs(n, m-1, cnt+1);
    seen[n][m] = false;
    chmax(ans, cnt);
}
int _main()
{
    cin >> N >> M;
    rep(i, N) rep(j, M) {
        cin >> G[i][j];
        seen[i][j] = false;
    }
    ans = 0;
    rep(i, N) rep(j, M) if(G[i][j]){
        dfs(i, j);
    }
    cout << ans << endl;
    return 0;
}