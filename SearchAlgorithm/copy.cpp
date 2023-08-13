#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep1(i,n) for(int i=1; i<=(n); i++)
#define sz(x) int(x.size())
#define all(x) (x).begin(),(x).end()
#define Q2 1000000007
#define Q 998244353
#define lINF 8000000000000000000  //ll
#define iINF (int)1<<30 //int
#define yes "Yes"
#define no "No"
#define kotae cout<<ans<<endl;
#define dame { puts("0"); return 0;}
#define yn {puts("Yes");}else{puts("No");}
using ll=long long;
using ull=unsigned long long;
using P=pair<int,int>;
using pqg=priority_queue<int,vector<int>,greater<int>>;
using vi=vector<int>;
using vi2=vector<vector<int>>;
using vi3=vector<vector<vector<int>>>;
using vl=vector<ll>;
using vl2=vector<vector<ll>>;
using vl3=vector<vector<vector<ll>>>;
using vs=vector<string>;
void chmax(int &x, int y){ x=max(x,y); return; }
void chmin(int &x, int y){ x=min(x,y); return; }
void chmaxl(ll &x, ll y){ x=max(x,y); return; }
void chminl(ll &x, ll y){ x=min(x,y); return; }

int main() {  

  int n;
  cin >> n;
  vi x(n),y(n),h(n);
  rep(i,n) cin >> x[i] >> y[i] >> h[i];
  int min;
  for(int i=0;i<=100;i++){
    for(int j=0 ;j<=100;j++){
      min=iINF;
      rep(k,n) chmin(min, h[k]+abs(i-x[k])+abs(j-y[k]));
      bool ok=true;
      rep(k,n) if(h[k]!=max(0, min-abs(i-x[k])-abs(j-y[k]))) ok=false;
      if(ok){
        cout<<i<<" "<<j<<" "<<min<<endl;
        return 0;
      }
    }
  }

  return 0;
}