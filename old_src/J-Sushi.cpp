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

int N;
double dp[310][310][310];

double rec(int i, int j, int k){
    if(dp[i][j][k] >= 0) return dp[i][j][k];
    if(i == 0 && j == 0 && k == 0) return 0.0;

    double res = 0.0;
    if(i > 0) res += rec(i-1,j,k)*i;
    if(j > 0) res += rec(i+1,j-1,k)*j;
    if(k > 0) res += rec(i,j+1,k-1)*k;
    res += N;
    res *= 1.0/(i+j+k);

    return dp[i][j][k]=res;
}
int main()
{
    cin >> N;
    int one=0, two=0, three=0;
    rep(i,N){
        int a; cin >> a;
        if(a == 1) ++one;
        else if(a == 2) ++two;
        else ++three;
    }

    memset(dp,-1,sizeof(dp));

    cout << fixed << setprecision(10) << rec(one,two,three) << endl;

    return 0;
}