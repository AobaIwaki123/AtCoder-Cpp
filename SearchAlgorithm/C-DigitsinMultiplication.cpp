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
    // 1 <= N <= 1e10
    ll N;
    cin >> N;
    ll ans = INF;
    // sqrt(N)以下の数字を全探索
    for (ll i = 1; i * i <= N; i++){
        // iがNの約数である時のみ処理を行う
        if (N % i == 0){
            ll a = i;
            ll b = N / i;
            ll sub = max(to_string(a).length(), to_string(b).length());
            ans = min(sub, ans);
        }
    }
    cout << ans << endl;
    return 0;
}