#include <iostream>
using namespace std;
int main(void){
    // 自分の得意な言語で
    // Let's チャレンジ！！
    // N M
    // p_{1,1} p_{1,2} p_{1,3}
    // p_{2,1} p_{2,2} p_{2,3}
    // ...
    // p_{N,1} p_{N,2} p_{N,3}
    // R_1 q_{1,1} q_{1,2} q_{1,3}
    // R_2 q_{2,1} q_{2,2} q_{2,3}
    // ...
    // R_M q_{M,1} q_{M,2} q_{M,3}
    int N,M;
    cin >> N >> M;
    int p[100][3];
    for(int i = 0; i < N; i++)
    {
        cin >> p[i][0] >> p[i][1] >> p[i][2];
    }
    int R[100], q[100][3];
    for(int i = 0; i < M; i++)
    {
        cin >> R[i] >> q[i][0] >> q[i][1] >> q[i][2];
    }
    for(int i = 0; i < M; i++)
    {
        if(R[i] == 'a')
        {
            // or
            for(int k = 0; k < N; k++)
            {
                for(int j = 0; j < 3; j++)
                {
                    p[k][j] = p[k][j] + q[i][j];
                    if(p[k][j] == 2) p[k][j] = 1;
                }
            }
        }
        else if(R[i] == 'b')
        {
            // and 
            for(int k = 0; k < N; k++)
            {
                for(int j = 0; j < 3; j++)
                {
                    p[k][j] = p[k][j] * q[i][j];
                }
            }
        }
        else if(R[i] == 'c')
        {
            // xor
            for(int k = 0; k < N; k++)
            {
                for(int j = 0; j < 3; j++)
                {
                    if(p[i][j] == q[i][j])
                    {
                        p[i][j] = 0;
                    }
                    else if(p[i][j] != q[i][j])
                    {
                        p[i][j] = 1;
                    }
                }
            }
        }
    }
    int max, sum = 0;
    int ans[100], cnt;
    max = p[0][0]*4 + p[0][1]*2 + p[0][2];
    ans[0] = 0;
    cnt = 1;
    for(int i = 1; i < N; i++)
    {
        sum = p[i][0]*4 + p[i][1]*2 + p[i][2];
        if(sum == max)
        {
            ans[cnt] = i;
            cnt++;
        }
        else if(sum > max)
        {
            ans[0] = sum;
            cnt = 1;
        }
    }
    for(int i = 0; i < cnt; i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}