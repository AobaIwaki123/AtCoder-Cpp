#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int N;
    cin >> N;
    int d[10000];
    for(int i = 0; i < N; i++) cin >> d[i];
    sort(d, d + N);
    int ans = d[N/2] - d[N/2-1];
    cout << ans << endl;
    return 0;
}