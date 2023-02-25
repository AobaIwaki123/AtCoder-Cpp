#include<iostream>
using namespace std;

long long N;
long long S[10];
long long A[10];

int main(){
    cin >> N;
    for(int i = 0; i < N; i++) cin >> S[i];
    A[0] = S[0];
    for(int i = 1; i < N; i++){
        A[i] = S[i] - S[i-1];
    }
    for(int i = 0; i < N; i++)
    {
        // 最後なら改行、それ以外なら空白の処理
        cout << A[i] << (i == N-1 ? "\n" : " ");
    }
    return 0;
}