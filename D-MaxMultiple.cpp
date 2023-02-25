#include<iostream>
#include<set>
#include<functional>
#include<bits/stdc++.h>

using namespace std;

// ランタイムエラーした
void recursive_comb(int *indexes, int s, int rest, std::function<void(int *)> f) {
  if (rest == 0) {
    f(indexes);
  } else {
    if (s < 0) return;
    recursive_comb(indexes, s - 1, rest, f);
    indexes[rest - 1] = s;
    recursive_comb(indexes, s - 1, rest - 1, f);
  }
}

// nCkの組み合わせに対して処理を実行する
void foreach_comb(int n, int k, std::function<void(int *)> f) {
  int indexes[k];
  recursive_comb(indexes, n - 1, k, f);
}
int K;
long long a[100];
long long sum = 0;
set<long long, greater<long long>>st;

int main(){
    int N, D;
    cin >> N >> K >> D;
    for(int i = 0; i < N; i++) cin >> a[i];

    foreach_comb(N, K, [](int *indexes) {
    // std::cout << indexes[0] << ',' << indexes[1] << std::endl;
    for(int i = 0; i < K; i++){
        // cout << indexes[i];
        sum += a[indexes[i]];
    }
    st.insert(sum);
    sum = 0;
    
    // cout << endl;
    });

    for (auto itr = st.begin(); itr != st.end(); ++itr) {
        if(*itr % D == 0){
            cout << *itr << endl;
            return 0;
        }
    }
    cout << -1 << endl;

    return 0;
}

// 模範解答
// 動的計画法を用いる

int main(){
  int N,K,D;
  cin >> N >> K >> D;

  vector<int> a(N);
  for(int i = 0; i < N; i++) cin >> a[i];
  // 全要素を-1で初期化
  vector dp(N+1, vector(K+1, vector<long long>(D, -1)));
  // 原点は0
  dp[0][0][0] = 0;

  for(int i = 0; i < N; i++){
    for(int j = 0; i < K+1; j++){
      for(int k = 0; k < D; k++){
        if(dp[i][j][k] == -1) continue;

        // a_i を選ばない場合の遷移
        dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j][k]);

        // a_i を選ぶ場合の遷移
        if(j != K){
          dp[i+1][j+1][(k+a[i])%D] = max(dp[i+1][j+1][(k+a[i])%D], dp[i][j][k] + a[i]);
        }
      }
    }
  }
  cout << dp[N][K][0] << endl;

  return 0;
}