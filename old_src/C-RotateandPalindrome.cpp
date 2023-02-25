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

ll N;
ll A,B;

bool check(ll N, string S){
    for(ll i = 0; i < N/2; ++i){
        if(S[i] == S[S.size()-i-1]) continue;
        else return false;
    }
    return true;
}

ll change(ll N, string S){
    ll sum = 0;
    for(ll i = 0; i < N/2; ++i){
        if(S[i] != S[S.size()-i-1]){
            sum += B;
        } 
    }
    return sum;
}
int _main()
{
    string S;
    cin >> N >> A >> B;
    cin >> S;
    ll ans = INF;

    if(check(N, S)){
        ans = 0;
        cout << ans << endl;
        return 0;
    }

    chmin(ans, change(N, S));

    for(ll i = 0; i < N/2; i++){
        string T = S.substr(0, 1);
        S.erase(0,1);
        S.insert(N-1,T);
        chmin(ans, change(N, S)+A*(i+1));
    }

    cout << ans << endl;
    return 0;
}