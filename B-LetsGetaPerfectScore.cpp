#include <bits/stdc++.h>
using namespace std;

// ほぼ模範解答通りだった

int N,M;
string S[40];
bool ans;
int cnt = 0;

int main()
{
    cin >> N >> M;
    for(int i = 0; i < N; i++) cin >> S[i];

    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            ans = 1;
            for(int k = 0; k < M; k++){
                if(S[i][k] == 'o' || S[j][k] == 'o') continue;
                else{
                    ans = 0;
                    break;
                } 
            }
            if(ans) cnt ++;
        }
    }
    cout << cnt << endl;
    return 0;
}