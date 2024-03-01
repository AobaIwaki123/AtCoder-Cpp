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
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    map<int, vector<ll>> D;
    rep(i, N) D[A[i]].push_back(i);
    
    ll S = accumulate(all(A), 0LL);
    vector<ll>ans(N);
    for(auto [v, i_list]:D){
        cout << v << endl;
        S -= (ll)v*i_list.size();
        for(auto i:i_list)ans[i]=S;
    }

    for(auto x:ans) cout << x << " ";
    return 0;
}