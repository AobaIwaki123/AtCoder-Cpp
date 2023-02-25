# AtCoder - C++ 

## 内容
- AtCoderやその他競技プログラミングの問題を解いた時のコード
  - 2023/02/25 : コードの管理方法を変更。以前は、ディレクトリ直下に全て保存していたが、多くなってきたのでこれらを`old_src/`に移動。今後は、大会名のディレクトリに保存する。
- 競技プログラミングに役立つVSCode用のテンプレート

## よく参考にする記事

- [厳選！C++ アルゴリズム実装に使える 25 の STL 機能【前編】](https://qiita.com/e869120/items/518297c6816adb67f9a5)

## テンプレート
```cpp
#include <bits/stdc++.h>
using namespace std; int _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll;
typedef pair<ll, ll> P;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define rrep(i, n) reps(i, 1, n + 1)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }



int _main()
{
    
    return 0;
}
```