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
    int n;
    int M;
    cin >> n >> M;
    vector<ll> A(n+1);
    A[0] = 0LL;
    for(int i = 1; i <= n; i++){
        cin >> A[i];
    }
    sort(all(A));
    vector<ll> B;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            ll score = A[i] + A[j];
            B.push_back(score);
        }
    }

    priority_queue<ll> pq;
    sort(all(B));
    for(ll i = 0; i < (int)B.size(); i++){
        ll idx = upper_bound(all(B), M-B[i]) - B.begin();
        if(M - B[i] < 0) continue;
        pq.push(B[i] + B[idx - 1]);
    }
    cout << pq.top() << endl;
    return 0;
}