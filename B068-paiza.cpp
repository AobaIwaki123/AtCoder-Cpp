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

int H,W;
int a[110][110];

int main()
{
    cin >> H >> W;
    int sum = 0;
    rep(i,H)rep(j,W+1){
        if(j==W){
            if(sum%2==1){
                cout << "No" << endl;
                // cout << sum;
                return 0;            
            }
            a[i][j] = sum;
            sum = 0;
        }
        else{
            cin >> a[i][j];
            sum += a[i][j];
            }
    }
    int cnt = 0;
    rep(i,H){
        sum = 0;
        rep(j,W){
            if(a[i][W]/2==sum){
                cnt++;
                break;
            }
            sum+=a[i][j];
        }
    }
    if(cnt!=H) {
        cout << "No" << endl;
        // cout << cnt << " " <<  H << endl;
    }
    else{
        cout << "Yes" << endl;
        rep(i,H){
            sum = 0;
            rep(j,W){
                sum += a[i][j];
                if(a[i][W]/2>=sum){
                    cout << 'A';
                }
                else{
                    cout << 'B';
                }
            }
            cout << endl;
        }
    }
    return 0;
}