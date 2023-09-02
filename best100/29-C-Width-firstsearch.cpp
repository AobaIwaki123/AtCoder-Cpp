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
    ll R, C;
    cin >> R >> C;
    ll sy, sx, gy, gx;
    cin >> sy >> sx >> gy >> gx;
    vector<vector<char>> c (55, vector<char>(55));
    vector<vector<ll>> dist (55, vector<ll>(55));

    dist.assign(R, vector<ll>(C, INF));
    c.assign(R, vector<char>(C, '.'));
    reps(i, 1, R+1){
        reps(j, 1, C+1){
            cin >> c[i][j];
        }
    }

    queue<pair<ll, ll>> que;
    que.emplace(make_pair(sy, sx));
    dist[sy][sx] = 0;
    while(que.size() != 0){
        pair<ll, ll> state = que.front();
        que.pop();

        if(state.first == gy && state.second == gx){
            break;
        }

        ll dy[4] = {0, 0, 1, -1};
        ll dx[4] = {1, -1, 0, 0};
        reps(i, 0, 4){
            pair<ll, ll> newstate = que.front();
            newstate.first = state.first + dy[i];
            newstate.second = state.second + dx[i];
            if(newstate.first < 0 || R <= newstate.first || newstate.second < 0 || C <= newstate.second ) continue;
            if(c[newstate.first][newstate.second] == '#') continue;
            if(dist[newstate.first][newstate.second] != INF) continue;
            que.push(newstate);
            dist[newstate.first][newstate.second] = dist[state.first][state.second] + 1;
        }
    }

    cout << dist[gy][gx] << endl;
    return 0;
}