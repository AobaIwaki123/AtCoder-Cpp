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
    vector<ll> A(N), P(N), Q(N);
    rep(i, N) cin >> P[i];
    rep(i, N) cin >> Q[i];
    rep(i, N) A[i] = i+1;
    ll dic = 0;
    ll dic_p, dic_q;
    do {
        dic++;
        ll cnt_p = 0;
        ll cnt_q = 0;
        rep(i, N){
            if (A[i] == P[i]){
                cnt_p++;
            }
            if (A[i] == Q[i]){
                cnt_q++;
            }
        }
        if (cnt_p == N){
            dic_p = dic;
        }
        if (cnt_q == N) {
            dic_q = dic;
        }
    } while (next_permutation(all(A)));
    cout << abs(dic_p - dic_q) << endl;
    return 0;
}

int _main(){
    
    return 0;
}