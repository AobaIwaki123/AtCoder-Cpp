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

ll H, W, N;
char M[1100][1100];

int _main()
{
    cin >> W >> H >> N;
    ll sw, sh; 
    rep(w, W) {
        rep(h, H) {
        char c; cin >> c;
        if(c == 'S') sw = w, sh = h;
        M[w][h] = c;
        // cout << M[w][h];
        }
        // cout << endl;
    }
    ll ans = 0;
    vector<vector<ll>> dist(1100, vector<ll>(1100));
    reps(cheese, 1, N+1){
        dist.assign(W, vector<ll>(H, INF));
        queue<pair<ll, ll>> que;
        que.emplace(make_pair(sw, sh));
        pair<ll, ll> start;
        start = que.front();
        dist[start.first][start.second] = 0;
        while(que.size() != 0){
            pair<ll, ll> state = que.front();
            que.pop();

            if(M[state.first][state.second] - '0' == cheese) { 
                ans += dist[state.first][state.second];
                sw = state.first;
                sh = state.second;
                // cout << sw << " " << sh << " " << M[sw][sh] << " ";
                // cout << dist[state.first][state.second] << endl;
                break;
            }

            ll dy[4] = {0, 0, 1, -1};
            ll dx[4] = {1, -1, 0, 0};

            reps(i, 0, 4){
                pair<ll, ll> newstate = que.front();
                newstate.first = state.first + dy[i];
                newstate.second = state.second + dx[i];
                if(newstate.first < 0 || newstate.first >= W || newstate.second < 0 || newstate.second >= H) continue;
                if(M[newstate.first][newstate.second] == 'X') continue;
                if(dist[newstate.first][newstate.second] != INF) continue;
                que.push(newstate);
                dist[newstate.first][newstate.second] = dist[state.first][state.second] + 1;
            }
        }
    }
    cout << ans << endl;
    return 0;
}