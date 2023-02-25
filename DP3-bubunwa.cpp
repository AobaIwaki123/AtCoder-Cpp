#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N,M;
    vector<int>A(110);
    cin >> N >> M;
    for(int i = 0; i < N; i++) cin >> A[i];
    bool dp[110][10010];

    memset(dp, 0, sizeof(dp));
    dp[0][0] = true;

    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            dp[i+1][j] |= dp[i][j];
            if(j >= A[i]) dp[i+1][j] |= dp[i][j-A[i]];
        }
    }

    if(dp[N][M]) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}