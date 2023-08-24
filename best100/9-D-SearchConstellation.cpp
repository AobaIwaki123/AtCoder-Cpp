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
    ll M; cin >> M;
    vector<ll> tx(M), ty(M);
    rep(i, M) cin >> tx[i] >> ty[i];
    ll N; cin >> N;
    vector<ll> ux(N), uy(N);
    rep(i, N) {
        cin >> ux[i] >> uy[i];
    }

    ll ax = -1;
    ll ay = -1;

    rep(i, N){
        ll dx = ux[i] - tx[0];
        ll dy = uy[i] - ty[0];
        ll cnt = 0;
        reps(j, 1, M){
            ll x = tx[j] + dx;
            ll y = ty[j] + dy;
            ll ok = false;
            rep(k, N){
                if(x == ux[k] && y == uy[k]) ok = true;
            }
            if(ok) cnt++;
        }
        // cout << cnt << endl;
        if(cnt == M-1){
            // cout << ux[i] << " " << uy[i] << endl;
            ax = dx;
            ay = dy;
        }
    }

    cout << ax << " " << ay << endl;
    return 0;
}