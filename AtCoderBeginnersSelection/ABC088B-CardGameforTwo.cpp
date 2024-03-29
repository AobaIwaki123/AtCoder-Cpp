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

ll N, A[200];

int _main()
{
    cin >> N;
    rep(i, N) cin >> A[i];
    sort(A, A+N, greater<ll>());
    ll sum_a = 0;
    ll sum_b = 0;
    rep(i, N){
        if(i % 2 == 0){
            sum_a += A[i];
        }else{
            sum_b += A[i];
        }
    }
    cout << sum_a - sum_b << endl;
    return 0;
}