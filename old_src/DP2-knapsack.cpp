#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N,W;
    cin >> N >> W;
    vector<int> weight(N);
    vector<int> value(N);
    for(int i = 0; i < N; i++) cin >> weight[i] >> value[i];

    vector<vector<int>> dp(N+1, vector<int>(W));
    // DPの初期条件を設定する
    for(int w = 0; w <= W; w++) dp[0][w] = 0;

    // DPのループ処理
    for(int i = 0; i < N; i++){
        for(int w = 0; w <= W; w++){
            // その荷物を入れることができるかどうかを判定する。
            // 可能な場合、その荷物の値を足し、その荷物を入れなかった場合の値と比較する
            if(w >= weight[i]) dp[i+1][w] = max(dp[i][w-weight[i]] + value[i], dp[i][w]);
            else dp[i+1][w] = dp[i][w];
        }
    }
    cout << dp[N][W] << endl;
    for(int i = 0; i < N; i++){
        for(int w = 0; w <= W; w++){
            cout << dp[i][w];
        }
        cout << endl;
    }
    return 0;
}