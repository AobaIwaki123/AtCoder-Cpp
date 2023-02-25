#include <bits/stdc++.h>
using namespace std;

const int INF = 1<<29;

int N,M;
int A[510], B[510];
int dp[510][10010];

int main()
{
    cin >> N >> M;
    for(int i = 0; i < N; i++) cin >> A[i] >> B[i];

    for(int i = 0; i < 110; i++) for(int j = 0; j < 10010; j++) dp[i][j] = INF;
    dp[0][0] = 0;

    for(int i = 0; i < N; i++){
        for(int j = 0; j <= M; j++){
            // i番目までの数字をいくつか選んだ総和がjになる時、i+1番目に対してもそれが成り立つ。
            // 理由：i+1番目の数字を選択しない場合、i番目までの数字だけを考えればよく、仮定より、i番目までは成り立っているから。
            // 例：i=0, j=0の時、i(=0)個の数字からいくつか選んだ総和がj(=0)になるには、0個の数字を選択すればいい。(何も選択しなければいい)
            // 次に、i=1, j=0を考えると、i+1個の数字から0個の数字を選択すれば総和は0となる。従って、これは任意のiについて成り立つ。
            if(dp[i][j] < INF) dp[i+1][j] = 0;
            // j>=A[i]ならば、A[i]を選択することができる。
            if(j >= A[i]){
                // 
                if(dp[i][j-A[i]] < INF){
                    // j=0の時のみ、0個を選択することで達成できるのでその結果を誤って更新しないためにminをとる。
                    dp[i+1][j] = min(dp[i+1][j], 1);
                }
                // dp[i+1][j-A[i]] < B[i]の時、追加でA[i]を選択することができる。
                // 選択することで、結果がよくなるならその値をminで選び取る。
                if(dp[i+1][j-A[i]] < B[i]){
                    dp[i+1][j] = min(dp[i+1][j], dp[i+1][j-A[i]] + 1);
                }
            }
        }
    }

    if(dp[N][M] < INF) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}