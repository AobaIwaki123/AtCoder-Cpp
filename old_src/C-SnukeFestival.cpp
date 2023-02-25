#include<iostream>
#include<algorithm>
using namespace std;

long long N;
long long A[100000];
long long B[100000];
long long C[100000];

int main(){
    cin >> N;
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < N; i++) cin >> B[i];
    for(int i = 0; i < N; i++) cin >> C[i];

    sort(A, A+N);
    sort(B, B+N);
    sort(C, C+N);

    long long ans = 0;

    for(int i = 0; i < N; i++){
        int index_B = lower_bound(B, B+N, A[i]+1) - B;
        for(int j = index_B; j < N; j++){
            int index_C = lower_bound(C, C+N, B[j]+1) - C;
            ans += N - index_C;
        }
    }

    cout << ans << endl;
    
    return 0;
}