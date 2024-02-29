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
    int n,q;
    cin >> n >> q;
    deque<pair<int, int>> d;
    reps(i, 1, n+1) d.push_back({i,0});

    while(q--){
        int t;
        cin >> t;
        if(t==1){
            char c;
            cin >> c;
            auto[x,y] = d[0];
            if(c=='R') d.push_front({x+1, y});
            if(c=='L') d.push_front({x-1, y});
            if(c=='U') d.push_front({x, y+1});
            if(c=='D') d.push_front({x, y-1});
            d.pop_back();
        }else{
            int x;
            cin >> x;
            x--;
            cout << d[x].first << " " << d[x].second << endl;
        }
    }
    return 0;
}