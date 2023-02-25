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

// 模範解答
// 考え方
// 1. S,Tの先頭x文字と末尾x文字が一致するかどうかを表す配列を事前に計算する。O(2|T|)
// 2. 問題文の条件に合うか判定処理を行う。O(|T|)

// 文字がマッチしているかどうかを確かめる関数
bool match_or_not(char a, char b) {
    return a=='?' || b == '?' || a == b;
}

int _main()
{
    string S,T;
    cin >> S >> T;
    vector<bool> pre(S.size()+1, false), suf(S.size()+1, false);
    pre[0] = true;
    // Sの先頭x文字とTの先頭x文字が一致するかどうかを表す配列を計算する
    rep(i,T.size()){
        if(!match_or_not(S[i],T[i]))break;
        pre[i+1] = true;
    }
    // 文字列S,Tを逆順に並べる
    reverse(all(S));
    reverse(all(T));
    suf[0] = true;
    // Sの末尾x文字とTの末尾x文字が一致するかどうかを表す配列を計算する
    rep(i,T.size()){
        if(!match_or_not(S[i],T[i]))break;
        suf[i+1] = true;
    }
    // 問題文の条件にあるかO(1)で判定する
    rep(i,T.size()+1){
        if(pre[i] && suf[T.size()-i]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}