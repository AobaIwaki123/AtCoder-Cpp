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

ll dx[] = { -1,0,1,0}; 
ll dy[] = { 0,1,0,-1};

int _main()
{
    ll H, W, N;
    cin >> H >> W >> N;
    char Map[110][110];
    ll X = 0, Y = 0, m=0;
    rep(h, H) rep(w, W){
        Map[h][w] = '.';
    }
    rep(n,N){
        if(Map[X][Y] == '.'){
            Map[X][Y] = '#';
            m++;
        }else{
            Map[X][Y] = '.';
            m+=3;
        }
        m %= 4;
        X += dx[m]; Y += dy[m];
        if(X < 0) X += H; if(X >= H) X -= H;
        if(Y < 0) Y += W; if(Y >= W) Y -= W;
    }
    rep(h,H){
        rep(w,W){
            cout << Map[h][w];
        }
        cout << endl;
    }

    return 0;
}