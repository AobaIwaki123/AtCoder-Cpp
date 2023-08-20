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
    vector<ll> T(N), X(N), Y(N);
    rep(i, N){
        cin >> T[i] >> X[i] >> Y[i];
    }
    ll time;
    ll diff;
    bool ok = true;
    rep(i, N){
        if(i == 0) {
            time = T[i];
            diff = abs(X[i] + Y[i]);
        } else{
            time = (T[i] - T[i-1]);
            diff = abs((X[i] - X[i-1]) + (Y[i] - Y[i-1]));
        }
        if(!(time%2 == diff%2 && time>=diff)) ok = false;
    }
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}