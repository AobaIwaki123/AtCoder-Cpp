#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
//#pragma GCC optimize ("-O3")
using namespace std; void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
//---------------------------------------------------------------------------------------------------
struct StringMaster {
    string S; int N; StringMaster() {}StringMaster(string s) { init(s); }
    void init(string s) { S = s; N = S.length(); initgo(); }

    // get the nearest index for the char
    vector<int> hidari[26], migi[26];
    inline void initgo() {
        rep(c, 0, 26) { migi[c].resize(N); migi[c][N - 1] = inf; }
        rrep(i, N - 2, 0) { rep(c, 0, 26) migi[c][i] = migi[c][i + 1]; migi[S[i + 1]][i] = i + 1; }
        rep(c, 0, 26) { hidari[c].resize(N); hidari[c][0] = -1; }
        rep(i, 1, N) { rep(c, 0, 26) hidari[c][i] = hidari[c][i - 1]; hidari[S[i - 1]][i] = i - 1; }
    }
    inline int gomigi(int cu, int c) { 
		if (cu == inf) return inf;
		if (cu < 0) {
			if (S[0] == c) return 0;
			cu = 0;
		}
		return migi[c][cu];
	}
    inline int gohidari(int cu, int c) {
		if (cu < 0) return cu;
		return hidari[c][cu];
	}
};
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan0
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














int N; string S;
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> S;

	fore(c, S) c -= '0';
	StringMaster sm(S);

	int ans = 0;
	rep(x0, 0, 10) rep(x1, 0, 10) rep(x2, 0, 10) {
		int cu = -1;
		cu = sm.gomigi(cu, x0);
		cu = sm.gomigi(cu, x1);
		cu = sm.gomigi(cu, x2);
		if (cu < inf) ans++;
	}
	cout << ans << endl;
}

// 別解
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 2e5+8, inf  = 1e18+9, mod  = 998244353;

int n, pre[maxn][10];
char s[maxn];
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0); //cout << fixed << setprecision(15);
    cin >> n >> (s + 1);
    for (int i = 0; i <= 9; i++) {
        int now = 0;
        pre[1][i] = now;
        if (s[1] - '0' == i) now = 1;
        for (int j = 2; j <= n + 1; j++) {
            pre[j][i] = now;
            if (s[j] - '0' == i) now = j;
        }
    }
    int ans = 0;
    for (int x = 0; x <= 9; x++) for (int y = 0; y <= 9; y++) for (int z = 0; z <= 9; z++) {
        int pos = pre[pre[pre[n + 1][z]][y]][x];
        if (pos >= 1) ans++;
    }
    cout << ans << endl;
    return 0;
}

// 別解
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rrep(i,n) for (int i = n; i >= 1; i--)
#define all(x) (x).begin(),(x).end()
using P = pair<int,int>;
using ll = long long;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }

int main() {
    int n;
    string s;
    cin >> n >> s;
    int count = 0;
    for(int i = 0; i < 1000; i++) {
        // 3桁の数字を生成する
        int c[3] = {i/100,(i%100) / 10, i%10};
        // 注目する数字のindexを0で初期化
        int index = 0;
        for(int j = 0; j < n; j++) {
            // 最初の数字が現れたらindexをすすめる
            if(s[j] == ('0' + c[index])) index++;
            // indexが最後まで進んでいたらcountをすすめる
            if(index == 3) {
                count++;
                break;
            }
        }
    }
    cout << count << endl;
}




