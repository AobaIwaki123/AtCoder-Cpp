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

// 3 <= N <= 100
int N;
// 0 <= x <= 300
int x;

int _main()
{
    cin >> N >> x;
    int cnt = 0;
    for (int i = 1; i <= N; i++){
        for (int j = i+1; j <= N; j++){
            for (int k = j+1; k <= N; k++){
                if (i + j + k == x) cnt ++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}