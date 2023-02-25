#include<iostream>
#include<algorithm>
using namespace std;
// 問題
// N個の整数 {a1,a2,...,aN} が与えられます。そのとき、L≤ai+aj≤R
// となるような (i,j)の組の個数を求めてください。
// 制約
// 1≤N≤1E6,1≤ai,K≤1E9

long long N, L, R, A[1000009];

int main(){
    cin >> N >> L >> R;
    for(int i = 0; i < N; i++) cin >> A[i];

    sort(A, A+N);

    long long ans;
    for(int i = 0; i < N; i++){
        int left_j = lower_bound(A, A+N, L-A[i]) - A;
        int right_j = lower_bound(A, A+N, (R+1LL) - A[i]) - A;
        ans += 1LL * (right_j - left_j);
    }
    cout << ans << endl;
    return 0;
}