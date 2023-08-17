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

#include <iomanip> // setprecisionを使用するのに必要

double distance(ll xi, ll xj, ll yi, ll yj){
    return sqrt((xi - xj) * (xi - xj) + (yi - yj) * (yi - yj));
}

int _main()
{
    ll N; cin >> N;
    ll X[10], Y[10];
    vector<ll> P(N);
    rep(i, N) {
        cin >> X[i] >> Y[i];
        P[i] = i;
    }
    double ans = 0;
    double cnt = 0;
    do {
        rep(i, N-1) {
            ll m1 = P[i];
            ll m2 = P[i+1];
            ans += distance(X[m1], X[m2], Y[m1], Y[m2]);
        }
        cnt ++;
    } while(next_permutation(P.begin(), P.end()));
    cout << std::fixed << std::setprecision(15) << ans / cnt << endl;

    return 0;
}