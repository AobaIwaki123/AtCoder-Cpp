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



int _main()
{
    ll N; cin >> N;
    string S; cin >> S;
    ll ans = 0;
    for(ll i = 0; i < 10; i++){
        for(ll j = 0; j < 10; j++){
            for(ll k = 0; k < 10; k++){
                ll cnt = 0;
                rep(l, N){
                    if(int(S[l] - '0') == i && cnt == 0) cnt++;
                    else if(int(S[l] - '0') == j && cnt == 1) cnt++;
                    else if(int(S[l] - '0') == k && cnt == 2) cnt++;
                } 
                if(cnt == 3) {
                    // cout << i << " " << j << " " << k << endl;
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}