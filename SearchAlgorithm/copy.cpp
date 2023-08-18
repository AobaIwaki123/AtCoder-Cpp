#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;

#define all(a) a.begin(),a.end()
#define pb push_back
#define sz(a) ((int)a.size())

int k,n,pw3[10];
string a[77],b[77],res[10];

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> k >> n;
    for(int i=0; i<n; ++i) cin >> a[i] >> b[i];
    pw3[0]=1;
    for(int i=1; i<10; ++i) pw3[i]=pw3[i-1]*3;
    for(int s=0; s<pw3[k]; ++s){
        for(int i=0; i<k; ++i) res[i].clear();
        bool ok=1;
        for(int i=0; i<n&&ok; ++i){
            int cur=0;
            for(auto c: a[i]){
                int len=s/pw3[c-'1']%3+1;
                if(cur+len>sz(b[i])){
                    ok=0;
                    break;
                }
                if(!res[c-'1'].empty()&&res[c-'1']!=b[i].substr(cur,len)){
                    ok=0;
                    break;
                }
                res[c-'1']=b[i].substr(cur,len);
                cur+=len;
            }
            if(cur!=sz(b[i])) ok=0;
        }
        if(ok){
            for(int i=0; i<k; ++i) cout << res[i] << "\n";
            return 0;
        }
    }
}