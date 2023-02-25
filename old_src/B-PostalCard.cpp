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

ll N,M;
string S[1010],T[1010];

int _main()
{
    cin >> N >> M;
    rep(i,N) cin >> S[i];
    rep(i,M) cin >> T[i];
    ll cnt = 0;
    rep(i,N){
        rep(j,M){
            if(S[i].substr(3) == T[j]){
                cnt++;
                break;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}