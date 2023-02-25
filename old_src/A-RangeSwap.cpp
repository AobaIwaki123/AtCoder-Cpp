#include <bits/stdc++.h>
using namespace std; int _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll;
// typedef pair<ll, ll> P;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define rrep(i, n) reps(i, 1, n + 1)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int N,P,Q,R,S;
int A[110];

int _main()
{
    cin >> N >> P >> Q >> R >> S;
    rrep(i,N) cin >> A[i];
    rrep(i,N){
        if(i<P)cout << A[i] << " ";
        else if(i==P){
            for(int j = R; j <= S; ++j){
                cout << A[j] << " ";
            }
        }
        else if(i>Q && i<R)cout << A[i] << " ";
        else if(i==R){
            for(int j = P; j <= Q; ++j){
                cout << A[j] << " ";
            }

        }
        else if(i>S) cout << A[i] << (i == N ? "\n" : " ");
    }
    return 0;
}