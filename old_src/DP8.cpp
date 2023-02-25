#include <bits/stdc++.h>
using namespace std;

string S,T;
int dp[1010][1010];

int main()
{
    cin >> S >> T;
    
    memset(dp, 0, sizeof(dp));

    for(int i = 0; i < S.size(); i++){
        for(int j = 0; j < T.size(); j++){
            dp[i+1][j+1] = max(dp[i+1][j+1], dp[i+1][j]);
            dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j+1]);
            if(S[i] == T[j]) dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + 1);
        }
    }
    cout << dp[S.size()][T.size()] << endl;
    return 0;
}