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

int N, Q;
vector<int> E[201010];
int val[201010];

void dfs(int cu, int pa = -1){
    for(int to : E[cu]) if(pa != to){
        val[to] += val[cu];
        dfs(to, cu);
    }
}
int _main()
{
    cin >> N >> Q;
    reps(i, 0, N-1){
        int a, b; cin >> a >> b;
        a--; b--;
        E[a].push_back(b);
        E[b].push_back(a);
    }

    reps(q, 0, Q){
        int p, x; cin >> p >> x;
        p--;
        val[p] += x;
    }

    dfs(0);

    reps(i, 0, N){
        if(i) cout << " ";
        cout << val[i];
    }
    cout << endl;
    return 0;
}