#include <bits/stdc++.h>
#include<atcoder/dsu>
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



// int _main()
// {
//     int N, Q;
//     cin >> N >> Q;
//     atcoder::dsu uf(N);
// 
//     for(int i = 0; i < Q; i++){
//         int type, u, v;
//         cin >> type >> u >> v;
//         if(type == 1)
//             cout << (uf.same(u,v) ? 1 : 0) << endl;
//         else
//             uf.merge(u, v);
//     }
//     return 0;
// }

struct UnionFind{
    vector<int> par;

    UnionFind() { }
    UnionFind(int n) : par(n, -1) { }
    void init(int n) { par.assign(n, -1);}

    int root(int x){
        if(par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }

    bool issame(int x, int y){
        return root(x) == root(y);
    }

    bool merge(int x, int y){
        x = root(x); y = root(y);
        if(x == y) return false;
        if(par[x] > par[y]) swap(x, y);
        par[x] += par[y];
        par[y] = x;
        return true;
    }

    int size(int x) {
        return -par[root(x)];
    }
}
int _main(){
    int N, Q;
    cin >> N >> Q;

    UnionFind uf(N);

    for(int i = 0; i < Q; i++){
        int type, u, v;
        cin >> type >> u >> v;
        if(type == 1)
            cout << (uf.issame(u, v) ? 1 : 0) endl;
        else
            uf.merge(u, v);
    }
    return 0;
}