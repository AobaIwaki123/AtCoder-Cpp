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
string S;

int main()
{
    cin >> N >> S;
    ll ans = 0;
    for(int i = 0; i < S.size(); i++){
        if(i+2 <= S.size() - 1 && S[i] == 'A' && S[i+1] == 'B' && S[i+2] == 'C') ans ++;
    }
    cout << ans << endl;
    return 0;
}