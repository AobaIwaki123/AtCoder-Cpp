#include <iostream>
#include <set>
#include <vector>
using namespace std;

// 模範解答
// bit全探索を用いる

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> a(M);

    for (int i = 0; i < M; i++) {
        int c;
        cin >> c;
        a[i].resize(c); // a[i]をcに合わせてリサイズする
        for (auto& x : a[i]) cin >> x; // こんな入力の仕方あるとは知らなかった
    }

    int ans = 0;

    // bit演算に関する調査をまとめる
    // 1 << x で二進数で1を左側にxbit進める。即ち、2倍する。
    // 1 << 1 << 1で2の累乗を表現できる
    for (int b = 0; b < (1 << M); b++) {
        set<int> s; // 集合を定義する

        for (int i = 0; i < M; i++) {
            if ((b >> i) & 1) {
                for (auto& x : a[i]) s.insert(x); // 集合にa[i]の要素を挿入する
            }
        }
        // 下のような記法を知らなかった
        // 左側がtrueの時、1として扱われ、1だけインクリメントされる
        ans += (int)s.size() == N; // 集合の要素がNに等しいならカウントする
    }
    cout << ans << "\n";
}
