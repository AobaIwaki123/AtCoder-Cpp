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
//     ll N; cin >> N;
//     vector<ll> D(N);
//     rep(i,N) cin >> D[i];
//     sort(all(D), greater<ll>());
//     ll ans = 0;
//     ll pre = INF;
//     rep(i, N) {
//         if(pre > D[i]){
//             pre = D[i];
//             ans++;
//         }
//     }
//     cout << ans << endl;
//     return 0;
// }

int _main(){
    int N;
    int d[110];
    cin >> N;
    rep(i, N) cin >> d[i];

    int num[110] = {0}; // バケット
    rep(i, N){
        num[d[i]]++;
    }
    int res = 0;
    rrep(i, 100){
        if(num[i]){
            ++res;
        }
    }
    cout << res << endl;
    return 0;
}

// int _main(){
//     int N;
//     int d[110];
//     cin >> N;
//     rep(i, N)cin >> d[i];
//     set<int> values;
//     rep(i, N){
//         values.insert(d[i]);
//     }
//     cout << values.size() << endl;
//     return 0;
// }