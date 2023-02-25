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
    int A[31],B[31];
    int C[31] = {0};

    cin >> N >> M;
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < M; i++) cin >> B[i];
    int people;
    int gondra = 0;
    for(int i = 0; i < M; i++){
        people = B[i];
        // 人数が正の間ゴンドラに乗り続ける
        while(people > 0){
            // ゴンドラの使用人数を記録
            C[gondra%N] += min(people,A[gondra%N]);
            // ゴンドラに乗った分人が減る
            people -= A[gondra%N];
            // 次のゴンドラが来る
            gondra++;
        }
    }
    for(int i = 0; i < N; i++) cout << C[i] << endl;
    
    return 0;
}