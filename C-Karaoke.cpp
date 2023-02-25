#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define rrep(i, n) reps(i, 1, n + 1)
const ll INF = 1LL << 60;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int N,M;
ll A[110][110];

int main()
{
    cin >> N >> M;
    rep(i,N)rep(j,M)cin >> A[i][j];
    ll ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < M; j++){
            ll sum = 0;
            rep(k,N){
                sum += max(A[k][i], A[k][j]);
            }
            chmax(ans,sum);
        }
    }
    cout << ans << endl;
    return 0;
}