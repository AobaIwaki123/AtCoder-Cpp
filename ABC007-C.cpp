#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();

// 幅優先探索の練習
int main()
{
    int R,C,sy,sx,gy,gx;
    char c[51][51];

    cin >> R >> C >> sy >> sx >> gy >> gx;
    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            cin >> c[i][j];
            // cout << c[i][j];
        }
        // cout << endl;
    }

    int dist[51][51];
    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            dist[i][j] = 1000000007;
        }
    }

    queue<pair<int, int>> Q;
    // cout << sx << sy << endl;
    Q.push(make_pair(sx,sy));
    dist[sx][sy] = 0;

    while(!Q.empty()){
        int cx = Q.front().first;
        int cy = Q.front().second;
        Q.pop();

        int dx[4] = {1,0,-1,0};
        int dy[4] = {0,1,0,-1};
        for(int i = 0; i < 4; i++){
            int ex = cx + dx[i];
            int ey = cy + dy[i];
            if(c[ex][ey] != '.' || dist[ex][ey] != 1000000007) continue;
            Q.push(make_pair(ex, ey));
            dist[ex][ey] = dist[cx][cy] + 1;
            // if(ex == gx && ey == gy){
            //     cout << "goal" << endl;
            //     break;
            // } 
        }
    }
    // for(int i = 1; i <= R; i++){
    //     for(int j = 1; j <= C; j++){
    //         if(dist[i][j] == 1000000007) cout << '#';
    //         else cout << dist[i][j];
    //     }
    //     cout << endl;
    // }
    cout << dist[gy][gx] << endl;

    return 0;
}