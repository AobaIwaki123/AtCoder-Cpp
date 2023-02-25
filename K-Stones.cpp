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
int a[110];
int dp[100010];

int main()
{
    cin >> N >> K;
    rrep(i,N) cin >> a[i];
    memset(dp,0,sizeof(dp));

    for(int i = 1; i <= K; i++){
        rrep(j,N){
            // 山の数iよりもa[j]が小さいなら選択することができる。
            // この時、dp[i-a[j]]=1であれば後攻が勝利するのでdpは更新されない。
            if(i - a[j] >= 0 && dp[i-a[j]] == 0){
                dp[i] = 1;
            }
        }
    }

    if(dp[K] == 1) cout << "First" << endl;
    else cout << "Second" << endl;
    return 0;
}