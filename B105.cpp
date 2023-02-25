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

int N;

int main()
{
    cin >> N;
    int ans = 0;
    for(int i = 1; i <= N; i++){
        int cnt = 2;
        if(i%2==1){
            for(int j = 2; j < i/2; j++){
                if(i%j==0){
                    if(j<i/j)cnt+=2;
                    else if(j==i/j)cnt++;
                }
            }
            // cout << i << " " << cnt << endl;
        }
        if(cnt==8)ans++;
    }
    cout << ans << endl;
    return 0;
}