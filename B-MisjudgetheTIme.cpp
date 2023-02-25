#include<iostream>
using namespace std;
#include <stdio.h>
#include <string>

int H,M;

int main(void)
{
    cin >> H >> M;
    while(true)
    {
        // 判定処理
        if(H < 20)
        {
            if(H%10 < 6) break;
        }
        else
        {
            if(H%10 < 6 && M < 40) break;
        }
        // 時刻を進める処理
        if(M + 1 == 60)
        {
            if(H + 1 == 24)
            {
                H = 0;
                M = 0;
            }
            else
            {
                H++;
                M = 0;
            }
        }
        else M ++;
    }
    cout << H << " " << M << endl;

    return 0;
}