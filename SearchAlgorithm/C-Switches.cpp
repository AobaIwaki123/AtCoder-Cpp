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

void Binary(int x) {
    int bit[30];
    for (int i = 0; i < 30; i++) {
        int Div = (1 << i);
        bit[i] = (x / Div) % 2;
        cout << bit[i];
    }
    cout << endl;
}


int _main()
{
    ll N, M;
    vector<ll> S[10];
    ll P[20];
    cin >> N >> M;
    rep(i, M){
        ll k; cin >> k;
        rep(j, k){
            ll s; cin >> s; s--;
            S[i].push_back(s);
        }
    }
    rep(i, M) cin >> P[i];

    ll ans = 0;
    // N個のスイッチのオンオフ状態に関するbit全探索
    rep(msk, 1 << N){
        ll ok = 0;
        // M個の電球について探索
        rep(m, M){
            ll cnt = 0;
            for (auto &s:S[m]) {
                // スイッチsのオンオフ状態を記録
                if (msk & (1 << s)) cnt++;
            }
            // m番目の電球のスイッチの状態のmod2がP[m]に等しいか確認
            if (cnt % 2 == P[m]) ok++; //　等しい場合、その電球mは点灯
        }
        // M個の電球全てが点灯する場合、ansをインクリメント
        if (ok == M) ans++; 
    }
    cout << ans << endl;
    return 0;
}