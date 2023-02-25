#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int INF = 1<<29; 
// 問題：N個の数字からいくつかの数字を選び、整数Mを作るときに必要な数字の個数の最小値を求める

int N,M,K;
int A[510];
int dp[510][10010];

int main()
{
    cin >> N >> M >> K;
    for(int i = 0; i < N; i++) cin >> A[i];
    
    for(int i = 0; i < 510; i++){
        for(int j = 0; j < 10010; j++){
            dp[i][j] = INF;
        }
    }

    
    dp[0][0] = 0;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j <= M; j++){
            dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
            if(j >= A[i]) dp[i+1][j] = min(dp[i+1][j], dp[i][j-A[i]]+1);
        }
    }
    
    if(dp[N][M] <= K) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}