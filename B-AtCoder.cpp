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

string S;

int main()
{
    cin >> S;
    ll ans = 0;
    ll cnt = 0;
    ll pos = -1;
    for(int i = 0; i < S.size(); i++){
        if(S[i] == 'A' || S[i] == 'C' || S[i] == 'G' || S[i] == 'T'){
            cnt++;
            if(pos+1==i){
                chmax(ans,cnt);
            }
            else{
                cnt=1;
                chmax(ans,cnt);
            }
            pos=i;
        }
    }
    cout << ans << endl;
    return 0;
}