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
    unordered_map<char, P> direction = {
        {'L', {-1, 0}},
        {'R', {+1, 0}},
        {'U', {0, -1}},
        {'D', {0, +1}},
    };

    ll H, W, N;
    cin >> H >> W >> N;
    string T;
    cin >> T;
    vector<string> S(H);
    rep(i, H) cin >> S[i];

    ll ans = 0;
    rrep(i, H) rrep(j, W){
        if(S[i][j] == '#') continue;
        P position = {i, j};
        bool ch = true;
        rep(k, T.size()){
            P dir = direction[T[k]];
            position.first = position.first + dir.first;
            position.second = position.second + dir.second;
            if(S[position.first][position.second] == '#') {
                ch = false;
                break;
            }
        }
        if(ch) ans++;
    }

    return 0;
}