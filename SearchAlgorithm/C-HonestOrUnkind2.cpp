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


ll N;
vector<ll> honests[15];
vector<ll> liars[15];

int _main()
{
    cin >> N;
    for (ll i = 0; i < N; i++){
        ll A; cin >> A;
        for(ll j = 0; j < A; j++){
            ll x, y; cin >> x >> y;
            // i番目の人が正直者もしくは不親切な人と証言した人を記録
            if (y == 0) liars[i].push_back(x - 1);
            else honests[i].push_back(x - 1);
        }
    }

    ll ans = 0;
    // 正直者、不親切な人を仮定してbit全探索を行う
    for(ll msk = 0; msk < 1 << N; msk++){
        bool ok = true;
        // 正直者の人数を初期化
        ll tot = 0;
        // i人目の人が正直者の場合処理を行う
        for (ll i = 0; i < N; i++) if (msk & (1 << i)){
            // 正直者の人数をインクリメント
            tot++;
            // i番目の人が正直者だと証言した人を全探索し、仮定にそうか判定
            for (auto &j:honests[i]){ 
                if (!(msk & (1 << j))) ok == false;
            }
            // i番目の人が不親切な人だと証言した人を全探索し、仮定にそうか判定
            for (auto &j:liars[i]) {
                if (msk & (1 << j)) ok = false;
            }
        }
        // 可能な組み合わせのうち、正直者が最も多い場合をansに格納
        if (ok) ans = max(ans, tot);
    }
    cout << ans << endl;
    return 0;
}

int _main(){
    cin >> N;
    for (ll i = 0; i < N; i++){
        ll A; cin >> A;
        for (ll j = 0; j < A; j++){
            ll x, y; cin >> x >> y;
            if (y == 0) liars[i].push_back(x - 1);
            else honests[i].push_back(x - 1);
        }
    }

    ll ans = 0;
    for (ll msk = 0; msk < 1 << N; msk++){
        bool ok = true;
        ll tot = 0;
        for (ll i = 0; i < N; i++) if (msk & (1 << i)){
            tot++;
            for (auto &j:honests[i]){
                if (!(msk & (1 << j))) ok = false;
            }
            for (auto &j:liars[i]){
                if (msk & (1 << j)) ok = false;
            }
        }
        if (ok) ans = max(ans, tot);
    }
    cout << ans << endl;
    return 0;
}