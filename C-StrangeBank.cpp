#include <bits/stdc++.h>
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

int N;
int dp[100010];

int f(int cu){
    if(cu == 0) return 0;
    if(dp[cu]) return dp[cu];
    int res = INT_MAX;
    // 1yen 
    chmin(res, f(cu-1)+1);
    // 6yen
    int x = 6;
    while(x <= cu){
        chmin(res, f(cu-x) + 1);
        x *= 6;
    }
    // 9yen
    x = 9;
    while(x <= cu){
        chmin(res, f(cu-x) + 1);
        x *= 9;
    }
    return dp[cu] = res;
}
int main()
{
    cin >> N;
    cout << f(N) << endl;
    return 0;
}