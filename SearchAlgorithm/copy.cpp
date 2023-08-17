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
//---------------------------------------------------------------------------------------------------
string buf = "";
void dfs(int cu) {
    if (cu == N) {
        printf("%s\n", buf.c_str());
        return;
    }

    char biggest = 'a';
    while (buf.find(biggest) != string::npos) biggest++;
    biggest--;

    for (char c = 'a'; c <= biggest + 1; c++) {
        buf.push_back(c);
        dfs(cu + 1);
        buf.pop_back();
    }
}
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N;

    dfs(0);
}