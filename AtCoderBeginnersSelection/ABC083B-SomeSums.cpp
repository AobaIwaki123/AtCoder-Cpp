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
    ll N, A, B;
    cin >> N >> A >> B;
    ll ans = 0;
    rrep(i, N){
        ll sum = 0;
        ll num = i;
        while(num>0){
            sum += num%10;
            num /= 10;
        }
        if(sum >= A && sum <= B) {
            ans += i;
        }
    }
    cout << ans << endl;
    return 0;
}