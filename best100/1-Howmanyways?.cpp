// #include <bits/stdc++.h>
// using namespace std; int _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
// typedef long long ll;
// typedef pair<ll, ll> P;
// #define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
// #define rep(i, n) reps(i, 0, n)
// #define rrep(i, n) reps(i, 1, n + 1)
// #define fore(i,a) for(auto &i:a)
// #define all(x) (x).begin(),(x).end()
// const ll INF = 1LL << 60;
// 
// template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
// template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
// 
// 
// 
// int _main()
// {   
//     while(true){
//         ll n, x; cin >> n >> x;
//         if(n == 0 && x == 0) break;
//         ll ans = 0;
//         reps(i, 1, n+1){
//             reps(j, i+1, n+1){
//                 reps(k, j+1, n+1){
//                     if(i + j + k  == x){
//                         cout << i << " " << j << " " << k << endl;
//                         ans ++;
//                     }
//                 }
//             }
//         }
//         cout << ans << endl;
//     }
//     return 0;
// }

#include<iostream>
using namespace std;

int main(){
    while(true){
        int n, x; cin >> n >> x;
        if(n == 0 && x == 0) break;
        int ans = 0;
        for(int i = 1; i <= n; i++){
            for(int j = i+1; j <= n; j++){
                for(int k = j+1; k <= n; k++){
                    if(i + j + k == x) ans ++;
                }
            }
        }
        cout << ans << endl;
    }
}