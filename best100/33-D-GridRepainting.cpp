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
    ll H, W;
    cin >> H >> W;
    char M[60][60];
    ll cnt = 0;
    ll dist[60][60];
    rep(h, H) rep(w, W) {
        char c; cin >> c;
        if(c == '#') cnt++;
        M[h][w] = c;
        dist[h][w] = INF;
    }
    ll ans = -1;
    queue<pair<ll, ll>> que;
    que.emplace(make_pair(0, 0));
    ll dy[4] = {0, 0, 1, -1};
    ll dx[4] = {1, -1, 0, 0};
    dist[0][0] = 0;
    while(!que.empty()){
        pair<ll, ll> state = que.front();
        if(state.first == H-1 && state.second == W-1) break;
        que.pop();
        rep(i, 4){
            pair<ll, ll> newstate = que.front();
            newstate.first = state.first + dy[i];
            newstate.second = state.second + dx[i];
            if(newstate.first < 0 || newstate.first >= H || newstate.second < 0 || newstate.second >= W) continue;
            if(dist[newstate.first][newstate.second] != INF) continue;
            dist[newstate.first][newstate.second] = dist[state.first][state.second] + 1;
            que.push(newstate);
        }
    }
    // cout << dist[H-1][W-1] << endl;
    if(dist[H-1][W-1] == INF) cout << ans << endl;
    else cout << H * W - (dist[H-1][W-1] + 1) - cnt << endl;
    return 0;
}