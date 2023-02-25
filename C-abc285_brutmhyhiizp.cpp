#include <bits/stdc++.h>
#include<iostream>
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

string S;

int main()
{
    cin >> S;
    ll ans = 0;
    for(ll i = S.size()-1; i >= 0; --i){

        ans = ans + (S[i]-'A'+1)*(ll)pow(26,(S.size()-1 - i));
    }
    cout << ans << endl;
    return 0;
}