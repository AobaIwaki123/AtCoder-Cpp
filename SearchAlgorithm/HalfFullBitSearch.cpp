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

ll N, X, A[40];
ll W1[1 << 20], W2[1 << 20];
bool flag = false;

int _main()
{
    cin >> N >> X;
    rep(i, N) cin >> A[i];
    // 前半のN/2個をbit全探索で全列挙
    rep(i, 1 << (N / 2)){
        ll sum = 0;
        rep(j, N / 2){
            if((i / (1 << j)) % 2 == 0) sum += A[j];
        }
        W1[i] = sum;
    }
    // 後半のN/2個をbit全探索で全列挙
    rep(i, 1 << (N - (N / 2))){
        ll sum = 0;
        rep(j, N - (N / 2)){
            if((i / (1 << j) % 2 == 0)) sum += A[j + (N / 2)];
        }
        W2[i] = sum;
    } 

    // ソート
    sort(W1, W1 + (1 << (N / 2)));
    sort(W2, W2 + (1 << (N - (N / 2))));
    rep(i, 1 << (N / 2)){
        ll rem = X - W1[i];
        int pos1 = lower_bound(W2, W2 + (1 << (N - (N / 2))), rem) - W2;
        if (W2[pos1] == rem) flag = true;
    }
    if(flag == true) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}