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
    reps(i, 0,N) cin >> A[i];

    const ll M = 1e6L+1;
    vector<ll> S(M);
    iota(all(S), 0);
    for(ll d = 1000; d >= 2; d--){
        for(ll k = d*d; k < M; k += d*d){
            if(S[k] % (d*d) == 0)S[k] /= d*d;
        }
    }

    vector<ll> cnt(M);
    reps(i, 0, N) cnt[S[A[i]]]++;
    ll ans = 0;
    reps(i, 0, M) ans += (ll)cnt[i]*cnt[i];
    cout << (ans - N)/2 + (ll)cnt[0]*(N-cnt[0]) << endl;
    return 0;
}