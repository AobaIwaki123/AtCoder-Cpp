#include <iostream>
using namespace std;

bool solve(int n) {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) cnt += 1;
    }
    if (cnt == 8 && n % 2 == 1) return true;
    return false;
}

int main() {
    int N, ans = 0;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        if (solve(i) == true) ans += 1;
    }
    cout << ans << endl;
    return 0;
}
