#include<bits/stdc++.h>
#include<atcoder/all>

using namespace std;
using namespace atcoder;
#define rep(i,n) for(ll i=0; i<n; i++)
#define rrep(i,n) for(ll i=n-1; i>=0; i--)
#define print(a) cout<<a<<endl;
typedef long long ll;
#define yn(flg) if(flg){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}
#define YN(flg) if(flg){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define so(a) sort(a.begin(),a.end())
#define mp make_pair
#define vi vector<int>
#define vl vector<ll>
#define vs vector<string>
#define pb push_back
#define a2i(a,s) (ll)(a-s)
#define i2a(s,a) (char)(s+a)
#define ssize(a) (ll)(a.size())
typedef pair<int, int> Pii;
typedef pair<int, ll> Pil;
typedef pair<pair<ll,ll>,ll> P3;
typedef pair<pair<ll,ll>,pair<ll,ll>> P4;

typedef pair<ll, ll> Pll;
typedef pair<ll,Pll> Plll;
typedef pair<Pii, int> Piii;
const ll INF = 1000000000000000000;

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
ll ans=INF;
ll n,k;
vector<ll> a(33);
void saiki(ll x,ll A,ll pos){
	if(x==k){
		ll T=0;
		ll I=1000000000,Z=5000000000;
		for(ll j=0;j<10;j++){
			if(pos<=0)break;
			T+=pos/Z;
			T+=pos%Z/I;
			pos=pos%Z%I;
			I=I/10;
			Z=Z/10;
		}
		ans=min(ans,T);
		return;
	}
	ll last=0;
	if(x>=1)last=A+1;
	for(ll i=last;i<min(n-k+x+1,n);i++){
		ll b=A,POS=pos,X=x;
		b=i;
		POS+=a[i];
		X++;
		saiki(X,b,POS);
	}
}

int main(){
//入力
	cin>>n>>k;
	rep(i,n)cin>>a[i];
	ll t=0;
	ll v=0;
	ll y=0;
	saiki(y,t,v);
//出力
	cout<<ans<<endl;

	return 0;

}
