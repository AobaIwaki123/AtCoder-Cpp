#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();

int main()
{
    int N, X, Y;
    cin >> N >> X >> Y;
    vector<int> P(N);
    for(int i = 0; i < N; i ++) cin >> P[i];
    sort(P.begin(), P.end());

    int ans = 0;
    if(N >= X){
        for(int i = 0; i < N-Y; i++){
            ans += P[i+Y];
        }
    }
    else{
        for(int i = 0; i < N; i++){
            ans += P[i];
        }
    }
    cout << ans << endl;
    return 0;
}