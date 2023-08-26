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
    cin >> N;
    vector<ll> P(N), Q(N);
    rep(i, N) cin >> P[i];
    rep(i, N) cin >> Q[i];
    vector<ll> ord;
    rep(i, N) ord.push_back(i+1);
    ll a,b;
    ll cnt = 0;
    do{
        cnt++;
        ll cnt_p = 0;
        ll cnt_q = 0;
        rep(i, N){
            if(ord[i] == P[i]) cnt_p++;
            if(ord[i] == Q[i]) cnt_q++;
        }
        if(cnt_p == N) a = cnt;
        if(cnt_q == N) b = cnt;
    } while (next_permutation(all(ord)));
    cout << abs(a - b) << endl;
    return 0;
}