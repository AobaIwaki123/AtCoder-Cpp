#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define rrep(i, n) reps(i, 1, n + 1)
const ll INF = 1LL << 60;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int N;
int F[3]={0};
ll D;

int main()
{
    cin >> N >> D;
    int A = D;
    while(A>1){
        if(A%2==0){
            F[0]++;
            A/=2;
        }
        if(A%3==0){
            F[1]++;
            A/=3;
        }
        if(A%5==0){
            F[2]++;
            A/=5;
        }
        cout << F[0] << " " << F[1] << " " << F[2] << endl;
    }

    return 0;
}