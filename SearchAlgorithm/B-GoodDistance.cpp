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

// 2 <= N <= 10, 1 <= D <= 10
int N, D;
int X[20][20];
int ans = 0;

float distance(int i, int j){
    float dist = 0;
    for (int k = 1; k <= D; k++){
        dist += (X[i][k] - X[j][k]) * (X[i][k] - X[j][k]);
    }
    return sqrt(dist);
}

bool is_int(float n){
    if (n - (int)n == 0){ 
        return true;
    }else{
        return false;
    }
}

int _main()
{
    cin >> N >> D;
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= D; j++){
            cin >> X[i][j];
        }
    }
    for (int i = 1; i <= N; i++){
        for (int j = i+1; j <= N; j++){
            if(is_int(distance(i, j))) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}