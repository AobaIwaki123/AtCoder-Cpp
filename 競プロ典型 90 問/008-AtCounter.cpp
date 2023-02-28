#include <iostream>
using namespace std;

string S;
long long mod = 1000000007;
// グローバルに定義された配列は、0で初期化される
// https://teratail.com/questions/168427
long long dp[100009][8]; 
char at[7] = {'a', 't', 'c', 'o', 'd', 'e', 'r'};

// 答えを見た
// 考え方
// 状態DPを用いた高速化

int main() {
	// Step #1. Input
	int N;
	cin >> N;
	cin >> S;

	// Step #2. Dynamic Programming (DP)
	dp[0][0] = 1;
	for (int i = 0; i < (int)N; i++) {
		for (int j = 0; j <= 7; j++) {
			dp[i + 1][j] += dp[i][j];
			if (S[i] == at[j]) dp[i + 1][j + 1] += dp[i][j];
		}
		for (int j = 0; j <= 7; j++) dp[i + 1][j] %= mod;
	}

	// Step #3. Output the answer
	cout << dp[N][7] << endl;
	return 0;
}