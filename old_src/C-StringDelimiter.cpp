#include <bits/stdc++.h>
using namespace std;

// 模範解答は、mod2ではなく真偽値の反転によって実装していた。

int N;
string S;

int main()
{
    cin >> N >> S;
    int cnt = 0;

    for(int i = 0; i < N; i++){
        if(S[i] == '"') cnt = (cnt + 1)%2;
        if(S[i] == ',' && cnt == 0) S[i] = '.';
    }
    cout << S << endl;
    return 0;
}