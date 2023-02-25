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

int N,M;
string s;
ll A[110],B[110];

bool isNumber(const string& str)
{
    for (char const &c : str) {
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}

int main()
{
    cin >> N >> M;
    memset(A,0,sizeof(A));
    memset(B,0,sizeof(B));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> s;
            if(isNumber(s)){
                if(stoi(s) >= 0 && stoi(s) <= 100){
                    A[j] += stoi(s);
                    B[j] ++;
                }
            }
        }
    }
    for(int j = 0; j < M; j++){
        if(B[j] == 0) cout << 0 << endl;
        else cout << A[j]/B[j] << endl;
    }
    

    return 0;
}