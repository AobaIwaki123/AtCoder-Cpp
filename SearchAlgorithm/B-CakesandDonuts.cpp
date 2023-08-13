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
//     // 1 <= N <= 100
//     ll N;
//     cin >> N;
//     ll num_b = 0;
//     while(7*num_b <= N){
//         ll num_a = 0;
//         while(4*num_a <= N){
//             ll price = 4*num_a + 7*num_b;
//             if (price == N){ 
//                 cout << "Yes" << endl;
//                 return 0;
//             }
//             num_a++; 
//         }
//         num_b++;
//     }
//     cout << "No" << endl;
//     return 0;
// }

int _main(){
    ll N;
    cin >> N;
    bool dp[200] = {};
    dp[0] = 1;
    for (int i = 1; i <= N; i++){
        if (i - 4 >= 0){
            if (dp[i-4]) dp[i] = 1;
            if (i - 7 >= 0){
                if (dp[i-7]) dp[i] = 1;
            }
        }
    }
    if(dp[N]) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}