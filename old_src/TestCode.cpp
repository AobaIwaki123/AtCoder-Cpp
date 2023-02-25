#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

vector<int> G[200005];

int main()
{
    G[0].push_back(1);
    cout << G << endl;
    for(auto u : G[0]){
        cout << u << endl;
    }
    return 0;
}