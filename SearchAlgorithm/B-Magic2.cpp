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
    // 1 <= A, B, C, <= 7
    ll A, B, C;
    // 1 <= K <= 7
    ll K;
    cin >> A >> B >> C;
    cin >> K;
    for (int i = 0; i < K; i++){
        if (A >= B){
            B *= 2;
        }else if (B >= C){
            C *= 2;
        }
    }
    if (A < B && B < C) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}