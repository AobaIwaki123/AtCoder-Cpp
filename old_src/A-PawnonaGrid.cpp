#include<iostream>
using namespace std;

long long H,W;
string S[10];
string s;

int main(void){
    cin >> H >> W;
    int ans = 0;
    for(int i = 0; i < H; i++) cin >> S[i];
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            s = S[i];
            if(s[j] == '#'){
                ans ++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}