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

int N,X;

int main()
{
    while(true){
        cin >> N >> X;
        if(N==0&&X==0)break;
        ll ans = 0;
        for(int i = 1; i <= N; i++){
            for(int j = i+1; j <= N; j++){
                for(int k = j+1; k <= N; k++)if(i+j+k==X)ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}