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

int N,size;
int X[3010],Y[3010];
int edge[4];

int _main()
{
    cin >> N;
    rep(i, N) cin >> X[i] >> Y[i];
    int ans = 0;
    for(int i = 0; i < N; ++i){
        for(int j = i+1; j < N; ++j){
            for(int k = j+1; k < N; ++k){
                memset(edge, 0, sizeof(edge));
                for(int l = k+1; l < N; ++l){
                    edge[0] = pow(Y[i]-Y[j],2)+pow(X[i]-X[j],2);
                    edge[1] = pow(Y[j]-Y[k],2)+pow(X[j]-X[k],2);
                    if(edge[0]!=edge[1])continue;
                    edge[2] = pow(Y[k]-Y[l],2)+pow(X[k]-X[l],2);
                    if(edge[2]!=edge[1])continue;
                    edge[3] = pow(Y[l]-Y[i],2)+pow(X[l]-X[i],2);
                    if(edge[3]!=edge[2])continue;
                    chmax(ans, edge[0]);
                }
            }
        }
    }
    return 0;
}