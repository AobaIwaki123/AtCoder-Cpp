#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();

int main()
{
    int N,M;
    vector<int>R;
    cin >> N >> M;
    vector<vector<int>>P(N, vector<int>(M));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> P[i][j];
            // cout << P[i][j];
        }
        // cout << endl;
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(find(R.begin(), R.end(), j+1) != R.end()) continue;
            else{
                if(P[i][j] >= M){
                    R.push_back(j+1);
                }
            }
        }
        // cout << R.size() << endl;
    }
    
    for(int i = 0; i < N; i++){
        if(find(R.begin(), R.end(), i+1) != R.end()) continue;
        else{
            cout << i+1 << (i == N-1 ? "\n" : " "); 
        }
    }
    if(R.size() == N) cout << "wait" << endl;
    return 0;
}