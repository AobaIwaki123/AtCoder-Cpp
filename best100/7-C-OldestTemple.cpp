#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;

int main()
{
    int n; cin >> n;
    vector<P> p(n);
    for(int i = 0; i < n; i++){
        cin >> p[i].first >> p[i].second;
    }

    sort(p.begin(), p.end());
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            int xi, yi; xi = p[i].first, yi = p[i].second;
            int xj, yj; xj = p[j].first, yj = p[j].second;
            int xdif, ydif; xdif = xi - xj; ydif = yi - yj;
            P q = make_pair(xi + ydif, yi - xdif);
            P r = make_pair(xj + ydif, yj - xdif);
            if(binary_search(p.begin(), p.end(), q) && binary_search(p.begin(), p.end(), r)){
                ans = max(ans, xdif*xdif + ydif * ydif);
            }
        }
    }
    cout << ans << endl;
    return 0;
}