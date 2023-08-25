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
    int n,a,q,m;
    cin >> n;
    bool dp[2001] = {true, false};
    for(int i = 0; i < n; i++){
        cin >> a;
        for(int j = 2000; j >= 0; j--){
            dp[j+a] |= (dp[j] && j + a < 2001);
        }
    }
    cin >> q;
    for(int i = 0; i < q; i++){
        cin >> m;
        cout << (dp[m] ? "yes" : "no") << endl;
    }
    return 0;
}