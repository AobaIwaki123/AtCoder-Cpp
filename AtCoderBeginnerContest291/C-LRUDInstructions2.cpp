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
    ll n; cin >> n;
    string s; cin >> s;

    set<P> st;
    P cord;
    cord.first = 0; cord.second = 0;
    st.insert(cord);

    rep(i,n){
        ll len = st.size();
        if(s[i] == 'R'){
            cord.first++;
            st.insert(cord);
        }
        else if(s[i] == 'L'){
            cord.first--;
            st.insert(cord);
        }
        else if(s[i] == 'U'){
            cord.second++;
            st.insert(cord);
        }
        else if(s[i] == 'D'){
            cord.second--;
            st.insert(cord);
        }
        if(len == st.size()){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    // for(auto x : st){
    //     cout << '(' << x.first << "," << x.second << ')' << endl;
    // }
    return 0;
}