#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define rrep(i, n) reps(i, 1, n + 1)
const ll INF = 1LL << 60;

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int N,K;
ll h[110000];
ll dp[110000];

int main()
{
    cin >> N >> K;
    for(int i = 0; i < N; i++) cin >> h[i];
    for(int i = 0; i < N; i++) dp[i] = INF;
    dp[0] = 0;
    for(int i = 1; i < N; i++){
        for(int j = 1; j <= K; j++){
            if(i-j>=0) chmin(dp[i], dp[i-j]+abs(h[i]-h[i-j]));
        }
    }
    cout << dp[N-1] << endl;
    return 0;
}