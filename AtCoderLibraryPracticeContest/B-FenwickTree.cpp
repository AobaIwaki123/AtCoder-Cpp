#include <bits/stdc++.h>
#include <atcoder/fenwicktree>
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
    int N, Q;
    cin >> N >> Q;

    atcoder::fenwick_tree<ll> bit(N);

    for(int i = 0; i < N; i++){
        ll a;
        cin >> a;
        bit.add(i, a);
    }
    for(int i = 0; i < Q; i++){
        int type;
        cin >> type;
        if(type == 0){
            ll p, x;
            cin >> p >> x;
            bit.add(p, x);
        } else {
            int l, r;
            cin >> l >> r;
            cout << bit.sum(l, r) << endl;
        }
    }
    
    return 0;
}