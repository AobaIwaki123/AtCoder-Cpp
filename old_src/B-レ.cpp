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

ll n,m;
ll a[200];

int _main()
{
    cin >> n >> m;
    rep(i,m) cin >> a[i];
    stack<ll> res;
    res.push(1);
    ll j = 0;
    rrep(i,n){
        if(res.empty()) res.push(i);
        if(i == a[j]){
            res.push(i+1);
            j++;
        }
        else{
            while(!res.empty()){
                cout << res.top() << " ";
                res.pop();
            }
        }
    }
    return 0;
}