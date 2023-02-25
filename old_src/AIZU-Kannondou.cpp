// #include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include <string>
#include <fstream>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define rrep(i, n) reps(i, 1, n + 1)
const ll INF = 1LL << 60;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

ll dp[31];

int main()
{
    memset(dp,0,sizeof(dp));
    dp[0] = 1;
    for(int i = 1; i <= 30; i++){
        dp[i] += dp[i-1];
        if(i-2>=0) dp[i] += dp[i-2];
        if(i-3>=0) dp[i] += dp[i-3];
    }

    rrep(i,30){
        // cout << dp[i] << " ";
        dp[i] = (dp[i]/10+365)/365;
        // cout << dp[i] << endl;
    }

    while(true){
        int N; cin >> N;
        if(N==0) break;
        cout << dp[N] << endl;
    }

    return 0;
}