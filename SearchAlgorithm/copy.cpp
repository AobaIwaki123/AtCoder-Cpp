#include <iostream>
#include <algorithm>
using namespace std;

long long N, X, A[40];
long long W1[1 << 20], W2[1 << 20];
bool flag = false;

int main() {
    cin >> N >> X;
    for (int i = 0; i < N; i++) cin >> A[i];

    // 前半 N/2 個を bit 全探索で全列挙する
    for (int i = 0; i < (1 << (N / 2)); i++) {
        long long sum = 0;
        for (int j = 0; j < (N / 2); j++) {
            if ((i / (1 << j)) % 2 == 0) sum += A[j];
        }
        W1[i] = sum;
    }

    // 後半 N - N/2 個を bit 全探索で全列挙する
    for (int i = 0; i < (1 << (N - (N / 2))); i++) {
        long long sum = 0;
        for (int j = 0; j < N - (N / 2); j++) {
            if ((i / (1 << j)) % 2 == 0) sum += A[j + (N / 2)];
        }
        W2[i] = sum;
    }

    // ソートしたうえで半分全列挙をする
    sort(W1, W1 + (1 << (N / 2)));
    sort(W2, W2 + (1 << (N - (N / 2))));
    for (int i = 0; i < (1 << (N / 2)); i++) {
        long long rem = X - W1[i];
        int pos1 = lower_bound(W2, W2 + (1 << (N - (N / 2))), rem) - W2;
        if (W2[pos1] == rem) flag = true;
    }
    if (flag == true) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
