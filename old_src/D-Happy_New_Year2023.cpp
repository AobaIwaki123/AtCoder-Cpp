#include <bits/stdc++.h>
#include<iostream>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define rrep(i, n) reps(i, 1, n + 1)
const ll INF = 1LL << 60;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int T;
ll N,p,q,r;
ll test[20];


int main()
{
    cin >> T;
    rep(i,T) {
        cin >> N;
        for(int j = 2; j <= sqrt(N); j++){
            r = pow(j,2);
            if(N%j==0 && N%r == 0){
                p = j;
                q = N/r;
                cout << p << " " << q << endl;
                break;
            }
            else if(N%j == 0){
                q = j;
                p = sqrt(N/q);
                cout << p << " " << q << endl;
                break;
            }
        }
    }
    return 0;
}