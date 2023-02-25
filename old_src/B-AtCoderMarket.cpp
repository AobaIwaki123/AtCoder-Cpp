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

// 考え方
// 1. 入り口sが出口sに対してs<tとなる時、計算が楽になることに気づく。（できなかった）
// 2. 直感的に入り口と出口は、a[i],b[i]のいずれかになることに気づく。(部分的に気づいた)
// 部分的に気づいたというのは、a[i]が入り口、b[i]が出口となると思い込んでしまった。
// 正確には、s<tとなるなら任意のa[i], b[i]の組み合わせが解となり得るっぽい。
ll n;
ll a[40],b[40];

ll calc(ll s, ll a, ll b, ll t){
    return (ll)abs(s-a) + (ll)abs(a-b) + (ll)abs(b-t);
}

int _main()
{
    cin >> n;
    rep(i,n) cin >> a[i] >> b[i];
    ll ans = INF;
    ll s = -1;
    ll t = -1;
    rep(i,2*n){
        if(i<n) s = a[i];
        else s = b[i-n];
        rep(j,2*n){
            if(j<n && a[j]>s) t = a[j];
            else if(j>=n && b[j-n]>s) t = b[j-n];
            else continue;
            ll sum = 0;
            rep(k,n){
                sum += calc(s, a[k], b[k], t);
            }
            chmin(ans, sum);
        }
    }
    cout << ans << endl;
    return 0;
}