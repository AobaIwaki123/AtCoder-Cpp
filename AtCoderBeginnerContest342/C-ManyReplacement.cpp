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

struct CompareFirst
{
    bool operator()(const std::pair<int, char> &lhs, const std::pair<int, char> &rhs) const
    {
        return lhs.first > rhs.first;
    }
};

int _main()
{
    ll N;
    cin >> N;
    string S;
    cin >> S;
    // cout << S << endl;
    ll Q;
    cin >> Q;
    map<char, char> rep;
    set<pair<ll, char>, CompareFirst> Updated;
    map<char, bool> searched;
    rep(i, 26) {
        rep['a'+i] = 'a'+i;
        searched['a' + i] = false;
        Updated.insert({0, 'a' + i});
    }
    // cout << endl;
    rep(i, Q){ 
        char C, D;
        cin >> C >> D;
        rep(j, 26){
            if (rep['a' + j] == C)
            {
                rep['a' + j] = D;
                Updated.insert({-i, 'a' + j});
            }
        }
    }
    for (const auto &pair : Updated)
    {
        std::cout << "(" << pair.first << ", " << pair.second << ") ";
    }
    for (const auto &pair : Updated)
    {
        char search = pair.second;
        if(searched[search])continue;
        searched[search] = true;
        rep(j, N){
            if (S[j] == search)
                S[j] = rep[search];
        }
    }
    // cout << endl;
    cout << S << endl;
    return 0;
}