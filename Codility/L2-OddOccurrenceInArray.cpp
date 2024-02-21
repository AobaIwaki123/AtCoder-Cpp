// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <bits/stdc++.h>
using namespace std; 
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

int solution(vector<int> &A) {
    // Implement your solution here
    sort(all(A));
    ll ans = 0;
    rep(i, A.size()){
        //cout << A[i] << " ";
        if(A[i] != A[i+1]){
            ans = A[i];
            break;
        }
        i++;
    }
    //cout << endl;
    if(ans == 0) ans = A[A.size() - 1];
    //cout << ans << endl;
    return ans;
}