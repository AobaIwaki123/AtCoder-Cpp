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

int N,M,T,K;
int a[110][110];
int sum[110],ans[110];

int main()
{
    cin >> N >> M >> T >> K;
    rep(i,M)rep(j,N) cin >> a[i][j];
    memset(sum,0,sizeof(sum));
    memset(ans,0,sizeof(ans));
    rep(i,M){
        rep(j,N){
            sum[j]+=a[i][j];
            if(i-T>=0)sum[j]-=a[i-T][j];
            if(sum[j]>=K){
                if(ans[j]==0)ans[j]=i+1;
            }
        }
    }
    rep(j,N){
        if(ans[j]==0){
            cout << "no" << " " << ans[j] << endl;
        }
        else{
            cout << "yes" << " " << ans[j] << endl;
        }
    }
    return 0;
}