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

int N, X[8], Y[8];

int _main()
{
    cin >> N;
    rep(i, N) cin >> X[i] >> Y[i];
    vector<int> ord;
    rep(i, N) ord.push_back(i);

    long double sm = 0;
    do{
        rep(i, N-1){
            int a = ord[i];
            int b = ord[i + 1];

            long double dx = X[a] - X[b];
            long double dy = Y[a] - Y[b];

            sm += sqrt(dx * dx + dy * dy);
        }
    } while (next_permutation(all(ord)));

    rep(i, N) sm /= (i+1);
    printf("%.10Lf\n", sm);
    return 0;
}