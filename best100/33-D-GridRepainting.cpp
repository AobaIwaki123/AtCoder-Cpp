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

int dirs[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

void solve(){
    int h,w;
    cin >> h >> w;
    vector<vector<char>> grid;

    int black = 0;

    rep(i, h){
        vector<char> v;
        rep(j, w){
            char x;
            cin >> x;
            v.push_back(x);

            if(x == '#'){
                black++;
            }
        }
        grid.push_back(v);
    }

    vector<vector<bool>> visited(h, vector<bool>(w, false));

    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));

    int dist = 0;
    bool found = false;
    while(!q.empty() && !found){
        int n = q.size();
        rep(i, n){
            auto p = q.front();
            q.pop();

            if(p.first == grid.size() - 1 && p.second == grid[0].size() - 1){
                found = true;
                break;
            }

            rep(j, 4){
                int newR = p.first + dirs[j][0];
                int newC = p.second + dirs[j][1];

                if(newR >= 0 && newR < grid.size() && newC >= 0 && newC < grid[0].size() &&
                !visited[newR][newC] && grid[newR][newC] == '.'){
                    visited[newR][newC] = true;
                    q.push(make_pair(newR, newC));
                }
            }
        }
        dist++;
    }
    if(!found){
        cout << - 1 << endl;
    }else{
        cout << h * w - black - dist << endl;
    }
}
int _main()
{
    solve();
    return 0;
}