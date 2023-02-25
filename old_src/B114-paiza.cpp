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

int N,K;
int r[20][20];
bool ans[20],cache[20];

int main()
{
    cin >> N >> K;
    rep(i,N){
        rep(j,K){ 
            cin >> r[i][j];
        }
        sort(r[i],r[i]+K,greater<int>());
    }
    // rep(i,N)rep(j,K) cout << r[i][j] << (j == K-1 ? "\n" : " ");
    memset(cache,1,sizeof(cache));
    rep(j,K){
        int flag = 0;
        int max = 0;
        rep(i,N){
            if(r[i][j]>max){
                memset(ans,0,sizeof(ans));
                ans[i]=1;
                flag=1;
                max=r[i][j];
            }
            else if(r[i][j]==max){
                ans[i]=1;
                flag=0;
            }
        }
        // cout << j << endl;
        // rep(i,N)cout << ans[i] << (i==N-1 ? "\n" : " ");
        // rep(i,N)cout << cache[i] << (i==N-1 ? "\n" : " ");
        rep(i,N) ans[i] &= cache[i];
        // rep(i,N)cout << ans[i] << (i==N-1 ? "\n" : " ");
        if(flag==1){
            rep(i,N)if(ans[i]==1)cout<<i+1<<endl;
            return 0;
        }
        rep(i,N)cache[i]&=ans[i];
    }
    rep(i,N)if(ans[i]==1)cout<<i+1<<endl;
    return 0;
}