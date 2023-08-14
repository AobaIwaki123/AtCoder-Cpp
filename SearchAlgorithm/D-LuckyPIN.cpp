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
    ll N;
    string S;
    cin >> N >> S;
    ll ans = 0;
    rep(i, 10){
        rep(j, 10){
            rep(k, 10){
                ll cnt = 0;
                rep(l, N){
                    ll value = S[l] - '0';
                    if (cnt == 0 && value == i) cnt++;
                    else if(cnt == 1 && value == j) cnt++;
                    else if(cnt == 2 && value == k) cnt++;
                }
                if (cnt == 3) ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}