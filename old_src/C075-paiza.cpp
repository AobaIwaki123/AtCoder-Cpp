#include <bits/stdc++.h>
using namespace std;

int N,M;
int f[110];

int main()
{
    cin >> N >> M;
    for(int i = 0; i < M; i++) cin >> f[i];

    int point = 0;
    for(int i = 0; i < M; i++){
        if(point < f[i] ){
            N -= f[i];
            point += f[i]/10;
        }
        else{
            point -= f[i];
        }
        cout << N << " " << point << endl;
    }
    return 0;
}