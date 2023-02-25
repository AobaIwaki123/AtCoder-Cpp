// #include <bits/stdc++.h>
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

struct edge{
    int to, cap, cost;
};

vector<edge> G[100];
int D[100];
int N,S,T,v,n,u,c;

int wfs(int v){
    int sum = 0;
    stack<int> st;
    for(auto u : G[v]){
        st.push(u.to);
        chmin(D[u.to], D[v]+G[v][0].cost);
    }
    while(!st.empty()) {
        wfs(st.top());
        st.pop();
    }
    return sum;
}

int main()
{

    //cinでファイルから読込
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());

    //cinの高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin >> N >> S >> T;
    rrep(i,N){
        cin >> v >> n >> u >> c;
        edge e = {n,u,c};
        G[v].push_back(e);
    }
    rrep(i,N) D[i] = INT_MAX;
    for(auto u : G[S]){
        cout << u.to << endl;
        cout << u.cap << endl;
        cout << u.cost << endl;
    }
    int ans;
    // ans = wfs();

    cout << ans << endl;

    return 0;
}