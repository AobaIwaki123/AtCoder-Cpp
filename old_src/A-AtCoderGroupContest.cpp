#include<iostream>
#include<algorithm>
using namespace std;
// ソートの練習
// 制約
// 1 < N < 1E5
// 1 < A[i] < 1E9
// A[i]は整数
// 注意点
// 和がオーバフローしない様にlong long 型にする

int main(){
    int N;
    cin >> N;
    long long A[10000];
    for(int i = 0; i < 3*N; i++) cin >> A[i];
    sort(A, A+3*N, greater<int>());
    long long sum = 0;
    for(int i = 0; i < N; i++) sum += A[N+i];
    cout << sum << endl;

    return 0;
}