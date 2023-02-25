// 考え方
// 与えられた辺の本数は、M本である
// 最大でL本の辺を残すことができるとすると、問題の答えはM-Lである
// ここで、グラフの連結成分の個数をSとする
// 頂点数がXの連結成分について考えると、適当な全域木をとることでX-1本は残すことができる
// 逆に、X本以上のへんを残すことはできない
// 各連結成分の大きさをX[1],X[2],...,X[S]とすると、L=SUM(X[i]-1)となる
// 頂点数Nは、N=SUM(X[i])と表せるので、L=N-Sと表せる
// グラフの連結成分の個数は、BFSなどで数えることができる(言われてみればそうだった)

// 模範解答:BFSを用いた実装
#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> graph(n, vector<int>()); // graphの定義
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	vector<bool> used(n);
	int s = 0;
	for (int i = 0; i < n; i++) {
		// used[i]に何も入っていなければif文の中に入る
		if (!used[i]) {
			s++; // 連結成分の個数をカウント
			queue<int> que; // キューの定義
			que.push(i); // キューに探索する頂点を格納する
			// キューが空でない場合、while loopを回す
			while (!que.empty()) {
				int q = que.front(); que.pop(); // queの先頭の要素を取り出し、先頭の要素を削除する
				// 頂点qに隣接する頂点vを探索する
				for (int v : graph[q]) {
					// 頂点vを探索済みでない場合、if文に入る
					if (!used[v]) {
						used[v] = true; // 頂点vに探索済みラベルをはる
						que.push(v); // キューに頂点vを格納する
					}
				}
			}
		}
	}
	cout << m - n + s << '\n'; // 数式の通りに計算する
}

// 模範解答:ACLを用いた解法
// 便利そうだけど勉強にならなそうだからパス

#include <iostream>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main() {
	int n, m;
	cin >> n >> m;
	dsu d(n);
	int ans = 0;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		if (d.same(u, v)) ans++;
		d.merge(u, v);
	}
	cout << ans << '\n';
}
