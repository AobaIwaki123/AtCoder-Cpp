#include <iostream>
using namespace std;

// 正の約数を8つ持つ数の個数をカウント
int N;
// 1 <= N <= 200
int ans = 0;

int main(){
    cin >> N;
    for (int i = 1; i <= N; i++){
        int cnt = 0;
        for (int j = 1; j <= i; j++){
            if (i%j == 0) cnt++;
        }
        if (cnt == 8){ 
            cout << i << endl;
            ans++;
        }
    }
    cout << ans << endl;
}

// お手本

bool solve(int n){
    int cnt = 0;
    for (int i = 1; i <= n; i++){
        if (n % i == 0) cnt +=1;
    }
    if (cnt == 8 && n %2 == 1) return true;
    return false;
}

int answer(){
    int N, ans = 0;
    cin >> N;
    for (int i = 1; i <= N; i++){
        if (solve(i) == true) ans += 1;
    }
    cout << ans << endl;
    return 0;
}