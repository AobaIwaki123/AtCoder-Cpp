#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define rrep(i, n) reps(i, 1, n + 1)
const ll INF = 1LL << 60;

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

// string s,t;
// string dp[3010][3010];
// 
// int main()
// {
//     cin >> s >> t;
//     if(s[0] == t[0]){
//         for(int i = 0; i < t.size(); i++) {
//             dp[i][0] += s[0];
//             dp[0][i] += s[0];
//         }
//     }
// 
//     for(int i = 1; i < s.size(); i++){
//         for(int j = 1; j < t.size(); j++){
//             if(s[i] == t[j]){
//                 if(dp[i-1][j-1].size()+1 > dp[i][j].size()) dp[i][j] = dp[i-1][j-1] + s[i];
//                 else dp[i][j] = dp[i][j];
//             }
//             else{
//                 if(dp[i][j].size() > dp[i][j-1].size()) dp[i][j] = dp[i][j];
//                 else dp[i][j] = dp[i][j-1];
//                 if(dp[i][j].size() > dp[i-1][j].size()) dp[i][j] = dp[i][j];
//                 else dp[i][j] = dp[i-1][j];
//             }
//         }
//     }
// 
//     cout << dp[s.size()-1][t.size()-1] << endl;
//     return 0;
// }

// 模範解答
string s,t;
int dp[3100][3100] = {0};

int main(){
    cin >> s >> t;
    rep(i,s.size()){
        rep(j,t.size()){
            if(s[i] == t[j]) chmax(dp[i+1][j+1], dp[i][j]+1);
            chmax(dp[i+1][j+1], dp[i+1][j]);
            chmax(dp[i+1][j+1], dp[i][j+1]);
        }
    }
    // cout << dp[s.size()][t.size()] << endl;
    string res = "";
    int i = (int)s.size(), j = (int)t.size();
    while(i > 0 && j > 0){
        if(dp[i][j] == dp[i-1][j]) --i;
        else if(dp[i][j] == dp[i][j-1]) --j;
        else{
            res = s[i-1] + res;
            --i,--j;
        }
    }
    cout << res << endl;
    return 0;
}