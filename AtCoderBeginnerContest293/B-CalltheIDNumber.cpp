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
    ll n; cin >> n;
    vector<bool> call(n+1,0);
    // cout << n << endl;
    ll cnt = 0;
    rrep(i,n){
        ll num; cin >> num;
        if(call[i]==0){
            call[num]=1;
        }
        // rrep(i,n) cout << call[i] << (i==n ? "\n" : " ");
    }
    cout << count(all(call),0)-1 << endl;
    rrep(i,n){
        if(call[i]==0){
            cout << i << " ";
        }
    }
    return 0;
}