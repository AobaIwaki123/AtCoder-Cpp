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



// int _main()
// {
//     ll M; ll D[200];
//     cin >> M;
//     ll sum = 0;
//     rep(i, M) {
//         cin >> D[i];
//         sum += D[i];
//     }
//     ll mid = (sum+1)/2;
//     ll month = 1;
//     ll date = 1;
//     sum = 0;
//     rep(i, M){
//         month = i + 1;
//         date = mid - sum;
//         sum += D[i];
//         if(sum >= mid) break;
//     }
//     cout << month << " " << date << endl;
// 
//     return 0;
// }

int _main(){
    ll m; cin >> m;
    vector<int> d(m);
    rep(i,m) cin >> d[i];

    int tot = 0;
    rep(i, m){
        tot += d[i];
    }

    int mid = (tot+1)/2;

    rep(i, m){
        if(mid <= d[i]){
            cout << i + 1 << " " << mid << endl;
            break;
        }
        else mid -= d[i];
    }
    return 0;
}