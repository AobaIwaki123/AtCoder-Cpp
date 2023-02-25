#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();

int main()
{
    int H,W;
    int s[1001][1001];

    cin >> H >> W;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> s[i][j];
        }
    }
    
    return 0;
}