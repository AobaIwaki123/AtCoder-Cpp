#include <bits/stdc++.h>
using namespace std; int _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
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



int _main()
{
    ll N, M;
    cin >> N >> M;
    string S;
    cin >> S;
    ll logo_max = 0;
    ll all_max = 0;
    ll logo_sum = 0;
    ll muji_sum = 0;
    rep(i, N){
        if(S[i] == '0'){
            chmax(logo_max, logo_sum);
            chmax(all_max, logo_sum + muji_sum);
            logo_sum = 0;
            muji_sum = 0;
        }else 
        if(S[i] == '1'){
            muji_sum++;
        }else
        if(S[i] == '2'){
            logo_sum++;
        }
    }
    chmax(logo_max, logo_sum);
    chmax(all_max, logo_sum + muji_sum);
    ll muji = (ll)max(all_max - logo_max - M, (ll)0);
    cout << logo_max + muji << endl;
    return 0;
}