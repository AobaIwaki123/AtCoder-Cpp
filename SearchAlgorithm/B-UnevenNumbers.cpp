// 整数 N が与えられます。N 以下の正の整数のうち、
// (先頭に 0 をつけずに十進法で表記したときの) 
// 桁数が奇数であるようなものの個数を求めてください。
#include <iostream>
using namespace std;

int N;
// 1 <= N <= 1e5
int ans = 0;

int get_digit(int n){
    int digit = 0;
    while (n > 0){
        digit++;
        n /= 10;
    }
    return digit;
}

int main(){
    // cout << get_digit(211) << endl;
    cin >> N;
    for (int i = 1; i <= N; i++){
        if (get_digit(i) % 2 == 1) ans++;
    }
    cout << ans << endl;
    return 0;
}