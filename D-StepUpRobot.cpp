#include <iostream>
#include <vector>

// 模範解答
// 考え方
// ロボットがk段目にいるときに、ここから、l段目に到達できるかどうかは、これまでどのような動き方をしてきたかは関係ないという考え方を用いる
// 今いる段数を状態としてもつDPを考える
// dp[i]=i段目に登ることができるなら1,できないなら0とするdp配列を考える
// すると、dp[i]は、餅の位置B[i]とより低い段に登れるかdp[0],dp[1],...,dp[i-1]の情報を用いて計算できる
// 言い換えると、餅が設置されていない段は、A[i]段目のどれかの段に登れるなら登れる。
// 初めは、0段目にいるのでdp[0]=1
// dp[-n]=0(n>0)であることに注意する

int main() {
    using namespace std;

    unsigned long N;
    cin >> N;
    vector<unsigned long> A(N);
    for (auto &&a : A)
        cin >> a; // 最近知ったvectorの値の入力方法

    unsigned long M;
    cin >> M;
    vector<unsigned long> B(M);
    for (auto &&b : B)
        cin >> b;

    unsigned long X;
    cin >> X;
    // dp[i] := i 段目に登れるか
    // available[i] := i 段目にモチがあるか(1で初期化)
    vector<unsigned long> dp(X + 1), available(X + 1, 1);
    for (const auto b : B)
        available[b] = 0; // 餅がある段を0にする

    // 0 段目には登れる
    dp[0] = 1;
    // 最悪計算量(1e6)
    // 下記の方法でiの初期値を決定できるのは初めて知った
    for (unsigned long i{1}; i <= X; ++i) // X段目に登れるかどうかをしらみつぶしに探索する(X<=1e5)
        if (!available[i])
            // モチがあると、登れない
            dp[i] = 0;
        else
            // モチがないとき、dp[i - a] の or が答え
            for (const auto a : A) // すべての登り方を探索する(A[N], N<=10)
                if (i >= a) // aを選択できるか判定
                    dp[i] |= dp[i - a]; // aを選択できる時にa段前に登れるか判定する

    // よくあるかっこいい記法。マスターしたい
    cout << (dp[X] ? "Yes" : "No") << endl;

    return 0;
}
