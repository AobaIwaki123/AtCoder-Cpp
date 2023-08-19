#include <iostream>
using namespace std;

struct State {
    bool used[7][7];
};

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int dfs(int N, int px, int py, State S) {
    if (px == N && py == N) return 1;

    int sum = 0;
    for (int i = 0; i < 4; i++) {
        // 次通る交差点を (sx, sy) とする
        int sx = px + dx[i];
        int sy = py + dy[i];
        if (sx < 0 || sy < 0 || sx > N || sy > N) continue;
        if (S.used[sx][sy] == true) continue;

        State NextState = S; NextState.used[sx][sy] = true;
        sum += dfs(N, sx, sy, NextState);
    }
    return sum;
}

int main() {
    // 入力
    int N; cin >> N;

    // 初期化
    State InitS;
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) InitS.used[i][j] = false;
    }
    InitS.used[0][0] = true;

    // 答えを求める
    cout << dfs(N, 0, 0, InitS) << endl;
    return 0;
}
