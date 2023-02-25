#include <bits/stdc++.h>
using namespace std;

int K;
char moji = 'A';

int main()
{
    cin >> K;

    for(int i = 0 ; i < K; i++) printf("%c", moji+i);
    cout << endl;

    return 0;
}

// 模範解答
int main()
{
    int k;
    cin >> k;
    for(int i = 0; i < k; i++){
        cout << char('A' + i);
    }
}