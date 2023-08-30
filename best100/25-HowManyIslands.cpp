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

bool M[60][60];
ll W, H;
bool seen[60][60];

bool dfs(ll h, ll w){
    if(seen[h][w]) return 0;
    seen[h][w] = 1;
    if(h+1 <  H) if(M[h+1][w]) dfs(h+1, w);
    if(h-1 >= 0) if(M[h-1][w]) dfs(h-1, w);
    if(w+1 <  W) if(M[h][w+1]) dfs(h, w+1);
    if(w-1 >= 0) if(M[h][w-1]) dfs(h, w-1);

    if(h+1 < H && w+1 < W ) if(M[h+1][w+1]) dfs(h+1, w+1);
    if(h+1 < H && w-1 >= 0) if(M[h+1][w-1]) dfs(h+1, w-1);
    if(h-1 >= 0 && w+1 < W ) if(M[h-1][w+1]) dfs(h-1, w+1);
    if(h-1 >= 0 && w-1 >= 0 ) if(M[h-1][w-1]) dfs(h-1, w-1);

    return 1;
}

void solve(){
    ll ans = 0;
    rep(i, H){
        rep(j, W){
            if(M[i][j]){
                if(dfs(i, j)) ans++;
            }
        }
    }
    cout << ans << endl;
}

int _main()
{
    while(true){
        cin >> W >> H;
        if(W == 0 && H == 0) break;
        rep(i, H) {
            rep(j, W) {
                cin >> M[i][j];
                seen[i][j] = 0;
            }
        }
        solve();
    }
    return 0;
}