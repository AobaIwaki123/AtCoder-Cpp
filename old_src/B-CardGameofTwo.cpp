#include<iostream>
#include <algorithm>
using namespace std;

// algorithmを用いると、sort関数を用いることができる。
// 昇順、降順はオプションで指定できる。

int main(){
    int N;
    cin >> N;
    int a[101];
    for(int i = 0; i < N; i++) cin >> a[i];
    sort(a, a + N, greater<int>());

    int v[2] = {0,0};
    for(int i = 0; i < N; i++){
        v[i % 2] += a[i];
    }

    int ans = v[0] - v[1];
    cout << ans << endl;
    return 0;
}