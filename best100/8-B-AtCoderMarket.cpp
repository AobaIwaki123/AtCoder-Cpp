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
    vector<ll> A(N), B(N);
    ll sum1 = 0; ll sum2 = 0; ll sum3 = 0;
    rep(i, N){
        ll a, b; cin >> a >> b;
        A[i] = min(a, b);
        B[i] = max(a, b);
        sum1 += abs(A[i] - B[i]);
    }
    sort(all(A)); sort(all(B));
    ll mid_a; ll mid_b;
    if(N % 2 == 1){
        ll mid = (N+1) / 2;
        mid_a = A[mid-1]; mid_b = B[mid-1];
    }else{
        ll mid = N/2;
        mid_a = (A[mid-1] + A[mid]) / 2;
        mid_b = (B[mid-1] + B[mid]) / 2;
    }
    rep(i, N){
        sum2 += abs(mid_a - A[i]);
        sum3 += abs(mid_b - B[i]);
    }
    cout << sum1 + sum2 + sum3 << endl;
    return 0;
}