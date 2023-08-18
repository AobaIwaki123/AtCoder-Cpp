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

int k, n, pw3[10];
string a[77], b[77], res[10];

int _main()
{
    cin >> k >> n;
    for(int i = 0; i < n; i++) cin >> a[i] >> b[i];
    // 初期化
    pw3[0] = 1;
    // 前の値の3倍の値を代入
    for(int i = 1; i < 10; i++) pw3[i] = pw3[i-1] * 3;
    // k番目の値を使用。kは使用される数の最大値
    // おそらく3進数でkを表現するまでループしている
    for(int s = 0; s < pw3[k]; s++){
        // string s[]の中の文字列を全てクリア=初期化
        for(int i = 0; i < k; i++) res[i].clear();
        // 判定用bool値を初期化
        bool ok = 1;
        // ok=1かつn以下でループ。nは、与えられた数字の個数
        for(int i = 0; i < n && ok; i++){
            // 文字列の長さを初期化
            int cur = 0;
            // string a[]の中身を探索。a[]に含まれるのは与えられた数列
            for(auto c: a[i]){
                // 数字cに対応する文字列の長さを計算
                int len = s / pw3[c-'1'] % 3 + 1;
                // curにlenを足した値が数列に対応する文字列全体よりも大きい場合、false
                if(cur + len > (int)b[i].size()){
                    ok = 0;
                    break;
                }
                // 数字cになんらかの文字列既にが入っており、かつ、
                // その文字列が今回対応する文字列と異なる場合、矛盾が生じるので、false
                if(!res[c-'1'].empty() && res[c-'1'] != b[i].substr(cur, len)){
                    ok = 0;
                    break;
                }
                // 数字cに対応する文字列を取得
                res[c-'1'] = b[i].substr(cur, len);
                // 文字列の長さを加算
                cur += len;
            }
            // 最終的な文字列の長さが対応する文字列の長さになっていなければ、false
            if(cur != (int)b[i].size()) ok = 0;
        }
        // 矛盾なく上の処理が終わった場合、答えを出力する
        if(ok){
            for(int i = 0; i < k; i++) cout << res[i] << endl;
            return 0;
        }
    }
    return 0;
}