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
    ll N;
    cin >> N;
    string S;
    cin >> S;
    ll Q;
    cin >> Q;
    string from = "abcdefghijklmnopqrstuvwxyz";
    string to = "abcdefghijklmnopqrstuvwxyz";
    rep(i, Q){
        char C, D;
        cin >> C >> D;
        for(auto &&m: to)
            if(m == C)
                m = D;
    }

    for(const auto c : S){
        for(unsigned i = 0; i < 26; ++i){
            if(c == from[i])
            cout << to[i];
        }
    }
    cout << endl;
    return 0;
}