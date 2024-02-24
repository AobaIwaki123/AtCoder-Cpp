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
    string S;
    cin >> S;
    ll ans = 0;
    char c1 = S[1];
    char c2 = S[2];
    char c3 = S[3];
    if(c1 == c2){
        reps(i, 2, S.size()){
            if(c1 != S[i]){
                ans = i + 1;
                break;
            }
        }
    }else{
        if(c1 == c3){
            ans = 2;
        } else {
            ans = 1;
        }
    }
    cout << ans << endl;
    return 0;
}