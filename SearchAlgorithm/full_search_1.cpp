#include <iostream>
using namespace std;

int N, K, A[59];
// 1 <= N <= 50
// 1 <= A[i], K <= 1e8
int cnt = 0;

int main(){
    // Input
    cin >> N >> K; 
    for (int i = 1; i <= N; i++) cin >> A[i];
    // 全探索
    for (int i = 1; i <= N; i++){
        for(int j = i+1; j<= N; j++){
            for(int k = j+1; k <= N; k++){
                // 総和がKになったらパターンをカウント
                if (A[i] + A[j] + A[k] == K) cnt += 1; 
            }
        }
    }
}