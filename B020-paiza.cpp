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
string S;
string Q[110];

int main()
{
    cin >> N;
    int j = 0;
    rep(i,N+1){
        //cout << i << endl;
        getline(cin,S);
        //cout << S << endl;
        if(S[0]=='g'){
            j++;
            Q[j] = S.substr(6);
            cout << Q[j] << endl;
        }
        else if(S[0]=='u'){
            j--;
            cout << Q[j] << endl;
        }
    }
    return 0;
}