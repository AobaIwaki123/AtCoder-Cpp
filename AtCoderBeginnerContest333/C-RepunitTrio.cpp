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
    ll M = 13;
    ll R[13];
    R[0] = 1;
    reps(i, 1, 13) {
        R[i] = R[i-1] + pow(10,i);
    }
    ll N; 
    cin >> N;

    rep(i, M){
        rep(j, i+1){
            rep(k, j+1){
                N--;
                if(N==0) cout << R[i] + R[j] + R[k] << endl;
            }
        }
    }
    return 0;
}