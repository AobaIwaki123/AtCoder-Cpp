#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

const int INF = 1<<29;


int N;
int h[100010];
int dp[100010];

int main()
{
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> h[i];
        // cout << h[i] << endl;
    }
    for(int i = 1; i <= N; i++){
        dp[i] = INF;
    }

    // cout << dp[N] << endl;

    dp[1] = 0;

    for(int i = 1; i <= N-1; i++){
        dp[i+1] = min(dp[i+1], dp[i] + abs(h[i] - h[i+1]));
        if(i <= N-2){
            dp[i+2] = dp[i] + abs(h[i] - h[i+2]);
        }
        // cout << dp[N] << endl;
        // cout << dp[i] << " " << dp[i+1] << " " << dp[i+2] << endl;
    }
    cout << dp[N] << endl;

    return 0;
}

// 模範解答
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

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

const ll INF = 1LL << 60;

// input
int N;
ll h[100010];

// dp table
ll dp[100010];

int main()
{
    cin >> N;
    for(int i = 0; i < N; i++) cin >> h[i];
    // initialilze
    for(int i = 0; i < 100010; i++) dp[i] = INF;
    // initial condition
    dp[0] = 0;
    // loop
    for(int i = 1; i < N; i++){
        chmin(dp[i], dp[i-1] + abs(h[i] - h[i-1]));
        if(i > 1) chmin(dp[i], dp[i-2] + abs(h[i] - h[i-2]));
    }
    // answer
    cout << dp[N-1] << endl;
    return 0;
}