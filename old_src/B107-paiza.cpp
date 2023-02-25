#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();

int main()
{
    int N,M,K;
    cin >> N >> M >> K;
    vector<int> C;
    vector<int> _C;

    for(int i = 0; i < N; i++) C.push_back(i+1);

    stack<int>a;
    int num;
    for(int k = 0; k < K; k++){
        for(int i = 0; i < N; i++){
            a.push(C[i]);
            if(a.size() == M){
                for(int j = 0; j < M; j++){
                    _C.push_back(a.top());
                    a.pop();
                }
            }
        }
        num = a.size();
        for(int j = 0; j < num; j++){
            _C.push_back(a.top());
            a.pop();
        }
        reverse(_C.begin(), _C.end());
        for(int i = 0; i < N; i++)C[i] = _C[i];
    }
    for(int i = 0; i < N; i++) cout << C[i] << endl;

    return 0;
}