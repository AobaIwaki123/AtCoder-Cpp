#include <bits/stdc++.h>
using namespace std;

int N, local, home;
string p[110];
int s[110];
string q,t, ans, _ans;
int main()
{
    cin >> N;
    for(int i = 0; i < N; i++) cin >> p[i] >> s[i];
    cin >> q >> t;
    for(int i = 0; i < N; i++){
        if(p[i] == q){
            home = s[i];
        }
    }
    //cout << home << endl;
    for(int i = 0; i < N; i++){
        int hours = stoi(t.substr(0,2));
        local = hours + s[i] - home;
        if(local >= 0){
            if(local < 10) _ans = '0' + to_string(local);
            else if(local == 24) _ans = "00";
            else _ans = to_string(local);
        }
        else{
            local = 24 + local;
            if(local < 10) _ans = '0' + to_string(local);
            else if(local == 24) _ans = "00";
            else _ans = to_string(local);
        }
        ans = _ans + t.substr(2);
        cout << ans << endl;
    }
    return 0;
}