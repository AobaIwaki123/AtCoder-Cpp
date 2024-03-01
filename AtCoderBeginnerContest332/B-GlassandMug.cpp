#include <bits/stdc++.h>
using namespace std;
int _main();
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    _main();
}
typedef long long ll;
typedef pair<ll, ll> P;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define rrep(i, n) reps(i, 1, n + 1)
#define fore(i, a) for (auto &i : a)
#define all(x) (x).begin(), (x).end()
const ll INF = 1LL << 60;

template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}

int _main()
{
    ll K, G, M;
    cin >> K >> G >> M;
    ll m = 0, g = 0;
    rep(i, K)
    {
        if (g == G)
            g = 0;
        else if (m == 0)
            m = M;
        else
        {
            ll sub = min(G - g, m);
            g += sub;
            m -= sub;
        }
    }
    cout << g << " " << m << endl;
    return 0;
}