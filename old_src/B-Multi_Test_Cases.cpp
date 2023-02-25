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

int T,N;
int ans[110];
ll A;

int main()
{
    cin >> T;
    memset(ans,0,sizeof(ans));
    rep(i,T){
        cin >> N;
        rep(j,N){
            cin >> A;
            if(A%2==1) ans[i]++;
        }
    }
    rep(i,T) cout << ans[i] << endl;
    return 0;
}