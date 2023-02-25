#include <bits/stdc++.h>
using namespace std;

int dp[110][10010];
int N,M;
int A[110];

int main()
{
    cin >> N >> M;
    for(int i = 0; i < N; i++) cin >> A[i];
    
    memset(dp, 0, sizeof(dp));   // 一旦すべて 0 に

    dp[0][0] = 1;

    for(int i = 0; i < N; i++){
        for(int j = 0; j <= M; j++){
            (dp[i+1][j] += dp[i][j]) %= 1000;
            if (j >= A[i]) (dp[i+1][j] += dp[i][j-A[i]]) %= 1000;
        }
    }

    cout << dp[N][M] << endl;
    return 0;
}