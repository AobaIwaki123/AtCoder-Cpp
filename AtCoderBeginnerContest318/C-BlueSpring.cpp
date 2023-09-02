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
    ll N, D, P; cin >> N >> D >> P;
    vector<ll> F(N);
    rep(i, N) cin >> F[i];
    sort(all(F), greater<ll>());
    ll cnt = 0;
    ll cnt_d = 0;
    ll sum_p = 0;
    rep(i, N){
        cnt++;
        sum_p += F[i];
        if(cnt == D || i == N-1){
            if(sum_p > P){
                cnt_d++;
            }
            cnt=0;
            sum_p = 0;
        }
    }
    ll ans = P * cnt_d;
    // cout << ans << endl;
    ll start;
    if(cnt_d > 0) start = cnt_d * D;
    else start = 0;
    if(start < N) reps(i, start, N){
        ans += F[i];
    }
    cout << ans << endl;
    return 0;
}