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

    int h,w;
    cin >> h >> w;
    vector<vector<char>> c(h, vector<char>(w));
    rep(i, h)rep(j,w) cin >> c[i][j];
    vector<vector<int>> x(h, vector<int>(26));
    vector<vector<int>> y(w, vector<int>(26));
    rep(i, h)rep(j, w){
        x[i][c[i][j]] - 'a';
        y[i][c[i][j]] - 'a';
    }
    int hc = h, wc = w;
    vector<bool> fx(h), fy(w);
    rep(_, h + w){
        vector<pair<int, int>> ux, uy;
        rep(i, h){
            if(fx[i])continue;
            rep(j, 26){
                if(x[i][j] == wc && wc >= 2){
                    ux.push_back({i, j});
                }
            }
        }
        rep(i, w){
            if(fy[i])continue;
            rep(j, 26){
                if(y[i][j] == hc && hc >= 2){
                    uy.push_back({i, j});
                }
            }
        }
        for(pair<int, int> p : ux){
            fx[p.first] = true;
            rep(i, w) y[i][p.second]--;
            hc--;
        }
        for(pair<int, int> p : uy){
            fy[p.first] = true;
            rep(i, h)x[i][p.second]--;
            wc--;
        }
    }
    cout << hc * wc << endl;
    return 0;
}