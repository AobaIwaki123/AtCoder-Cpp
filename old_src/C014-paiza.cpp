#include <bits/stdc++.h>
using namespace std;

int n,r;
int h[110], w[110], d[110];

int main()
{  
    cin >> n >> r;
    for(int i = 0; i < n; i++) cin >> h[i] >> w[i] >> d[i];

    for(int i = 0; i < n; i++){
        if(r <= h[i] && r <= w[i] && r <= d[i]){
            cout << i << endl;
        }
    }
    return 0;
}