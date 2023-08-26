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

int n, m;
int e[11][11];
int used[11];
int ans;

void dfs(int v, int sum){
    used[v] = 1;
    ans = max(ans, sum);
    rrep(i, n){
        if(!used[i] && e[v][i]){
            dfs(i, sum + e[v][i]);
        }
    }
    used[v] = 0;
}

int _main()
{
    cin >> n >> m;
    rep(i, m){
        int a, b, c;
        cin >> a >> b >> c;
        e[a][b] = e[b][a] = c;
    }
    rrep(i, n) dfs(i, 0);
    cout << ans << endl;
    return 0;
}