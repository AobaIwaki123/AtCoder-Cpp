#include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include <string>
#include <fstream>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define rrep(i, n) reps(i, 1, n + 1)
const ll INF = 1LL << 60;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int N; // 3<=N<=100
int A;
int main()
{
    //cinでファイルから読込
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());

    //cinの高速化
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    vector<vector<int>> g(N);
    ll ans = 0;
    rep(i,N){
        cin >> A;
        if(i==0){
            g[0].push_back(A);
        }
        else if(i==N-1){
            for(auto u : g[i-1]){
                if(u == A) ans ++;
            }
            cout << ans << endl;
            return 0;
        }
        else{
            for(auto u : g[i-1]){
                if(u+A>=0 && u+A<=20) g[i].push_back(u+A);
                if(u-A>=0 && u-A<=20) g[i].push_back(u-A);
            }
        }

    }
    return 0;
}

// 模範解答
#include <bits/stdc++.h>
using namespace std;

int main() {
    int a,c;
    cin>>a;
    vector<vector<int64_t>> b(a+1,vector<int64_t>(21));
    cin>>c;
    b.at(0).at(c)++;

    for(int i=0;i<a-2;i++){
        cin>>c;
        for(int j=0;j<=20;j++){
            if(0<=j+c&&j+c<=20)b.at(i+1).at(j+c)+=b.at(i).at(j);
            if(0<=j-c&&j-c<=20)b.at(i+1).at(j-c)+=b.at(i).at(j);
        }
    }
    
    cin>>c;
    cout<<b.at(a-2).at(c)<<endl;
}