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

// 1 <= N <= 100
int N;

int ans = 1;
int max_cnt = 0;

int solver(int n){
    int cnt = 0;
    while(n > 1){
        if (n % 2 == 0){
            n /= 2;
            cnt++;
        }
        else{
            return cnt;
        }
    }
    return cnt;
}
int _main()
{
    cin >> N;
    for (int i = 1; i <= N; i++){
        if (solver(i) > max_cnt){
            max_cnt = solver(i);
            ans = i;
        }
    }
    cout << ans << endl;
    return 0;
}