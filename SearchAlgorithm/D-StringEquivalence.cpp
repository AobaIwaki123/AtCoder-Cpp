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

int N;
string buf = "";

// 問題の制約から既出の文字より辞書的に1つだけ大きな文字だけ後ろに追加することができる
// その時点での最大の文字を更新しながら再帰的に文字列の生成を行う
void dfs(int cu){
    // 文字列の長さがNの時に処理を行う
    if (cu == N){
        // 以下はcoutでもACするが、prinfの方が速度が10倍速かった
        // その時点での文字列を表示してreturn
        printf("%s\n", buf.c_str());
        // cout << buf << endl;
        return;
    }
    // 既出の文字で最大のもの
    char biggest = 'a';
    // string::nposは、findで見つからないときに返却される値
    // biggestを更新する
    // 文字列が長くなるとbiggestの値が大きくなり、文字列の多様性が増加する
    while (buf.find(biggest) != string::npos) biggest++;

    // 'a'からbiggestまで探索
    for (char c = 'a'; c <= biggest; c++){
        // bufにcを格納
        buf.push_back(c);
        // 深いdfsに入る
        dfs(cu + 1);
        // bufからcをpop
        buf.pop_back();
    }
}

int _main()
{
    cin >> N;
    dfs(0);
    return 0;
}