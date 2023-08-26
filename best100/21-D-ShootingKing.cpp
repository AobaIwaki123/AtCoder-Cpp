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

ll h[100005], s[100005], n;
ll t[100005];

bool check(ll x){
    // 高度xを超えてはいけないとする
    rrep(i, n){
        // この時、x < h[i]ならば成り立たない
        if(x < h[i]) return false;
        // また、以下の時間内に風船iを割る必要がある
        t[i] = (x - h[i]) / s[i];
    }
    // 風船を割る時間をソート
    sort(t+1, t+n+1);
    // 風船を時間内に割れるか判定
    rrep(i, n){
        if(t[i] < (i-1)) return false;
    }
    return true;
}

int _main()
{
    cin >> n;
    ll l = 1, r = 0, ans = 0;
    rrep(i, n){
        cin >> h[i] >> s[i];
        // 最大高度を計算
        r = max(r, h[i] + (n-1) * s[i]);
    }
    // 高度xを二分探索
    while(l <= r){
        // midを計算
        // 右に1シフトすることは、2で割ることに等しい
        ll mid = (l + r) >> 1;
        // 高度がmid以下で、風船を全て時間内に割れるか判定
        if(check(mid)) r = mid - 1, ans = mid;
        else l = mid + 1;
    }
    // 高度x以下で全ての風船が割れるという条件のもとでのxの最小値が入る
    cout << ans << endl;
    return 0;
}