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
    string S; cin >> S;
    reverse(all(S));
    // dream dreamer erase eraser
    string R[4] = {"maerd", "remaerd", "esare", "resare"};
    // cout << R[0] << " " << R[0].size() << " " << S.substr(0, R[0].size()) << endl;
    ll pos = 0;

    while(true){
        bool ok = false;
        rep(i, 4){
            // cout << S.substr(pos, R[i].size()) << endl;
            if(R[i] == S.substr(pos, R[i].size())) {
                pos += R[i].size();
                ok = true;
            }
            if(ok){
                // cout << S.substr(pos, S.size()) << endl;;
                break;
            }
        }
        if(ok == false) break;
    }
    if(S.size() == pos) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}