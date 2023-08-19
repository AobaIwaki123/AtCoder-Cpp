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



// int _main()
// {
//     ll N; cin >> N;
//     vector<ll> F(N+1);
//     vector<ll> S(N+1);
//     vector<ll> A(N+1, 0);
//     vector<ll> B(N+1, 0);
//     rep(i, N) {
//         cin >> F[i] >> S[i];
//         if(S[i] > A[F[i]]) {
//             chmax(B[F[i]], A[F[i]]);
//             A[F[i]] = S[i];
//         } else if (S[i] > B[F[i]]) {
//             B[F[i]] = S[i];
//         }
//     }
//     sort(all(A), greater<ll>());
//     sort(all(B), greater<ll>());
//     ll a = A[0] + B[0]/2;
//     ll b = A[0] + A[1];
//     cout << max(a, b) << endl;
// 
//     
//     return 0;
// }

int _main(){
    int n;
    cin >> n;
    vector<vector<int>> bk(n+1);
    for(int i = 0; i < n; i++){
        int f,s;
        cin >> f >> s;
        bk[f].push_back(s);
    }

    int res = 0;
    vector<int>best;
    for(int i = 1; i <= n; i++){
        // ソート
        sort(bk[i].begin(), bk[i].end());
        // 反転
        reverse(bk[i].begin(), bk[i].end());
        // 同じものが2つ以上ある場合
        if(bk[i].size() >= 2){
            // 大きい方を代入
            res = max(res, bk[i][0] + bk[i][1]/2);
        }
        // 同じものが1つ以上の場合
        if(bk[i].size() >= 1){
            // 最大値を保存
            best.push_back(bk[i][0]);
        }
    }
    // 最大値をソート
    sort(best.begin(), best.end());
    // 反転
    reverse(best.begin(), best.end());
    // 最大値が2つ以上ある場合、合計値を計算
    if(best.size()>=2){res=max(res, best[0] + best[1]);}
    cout << res << endl;
    return 0;
}