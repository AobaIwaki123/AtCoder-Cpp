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

int W,N,K;
int A[60],B[60];
int dp[10010][60];

int main()
{
    cin >> W;
    cin >> N >> K;
    rep(i,N) cin >> A[i] >> B[i];
    memset(dp,0,sizeof(dp));
    for(int i = 1; i <= W; i++){
        for(int j = 1; j <= K; j++){
            dp[i][j] = dp[i-1][j];
            rep(k,N){
                if(A[k] <= i) chmax(dp[i][j], dp[i-A[k]][j-1]+B[k]);
            }
        }
    }
    
    cout << dp[W][K] << endl;

    return 0;
}

// 模範解答
// LUOGU_RID: 98697756
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=55;
int n,x,y;
int a[N],b[N],dp[10005][N];
int main(){
	scanf("%d%d%d",&x,&n,&y);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i],&b[i]);			
	}
	for(int i=1;i<=n;i++){
		for(int j=x;j>=a[i];j--){
			for(int k=y;k>=1;k--){
				dp[j][k]=max(dp[j][k],dp[j-a[i]][k-1]+b[i]);
			}
		}
	}
	printf("%d",dp[x][y]);
	return 0;
}