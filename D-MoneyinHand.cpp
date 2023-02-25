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

int N,X;
int A[60],B[60];
bool dp[2510][10010];

int _main()
{
    cin >> N >> X;
    for(int i = 0; i < N; i++) cin >> A[i] >> B[i];
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;
    ll cnt = 1;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < B[i]; j++){
            for(int k = 0; k <= X; k++){
                dp[cnt][k] = dp[cnt-1][k];
                if(k-A[i] >= 0){
                    dp[cnt][k] |= dp[cnt-1][k-A[i]];
                }
            }
            cnt++;
        }
    }
    if(dp[cnt-1][X] == 0)cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}