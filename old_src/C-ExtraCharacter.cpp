#include<iostream>
using namespace std;

string S,T;

int main(){
    cin >> S >> T;
    // cout << S << T << endl;
    for(int i = 0; i < (int)S.size(); i++){
        if(S[i] != T[i]){
            cout << i+1 << endl;
            return 0;
        }
    }
    cout << S.size()+1 << endl;
    return 0;
}

