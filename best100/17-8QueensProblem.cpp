#include <bits/stdc++.h>

using namespace std;

vector<int> X(8), Y(8);

void display(){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            bool exist = false;
            for(int k = 0; k < 8; k++){
                if(i == X[k] && j == Y[k]) exist = true;
            }
            if(exist) cout << 'Q';
            else cout << '.';
        }
        cout << endl;
    }
}

int main(){
    int K; cin >> K;
    for(int i = 0; i < K; i++) cin >> X[i] >> Y[i];

    vector<int> ord;
    for(int i = 0; i < 8; i++) ord.push_back(i);
    do{
        bool ok = true;
        for(int i = 0; i < K; i++){
            if(ord[Y[i]] != X[i]) ok = false;
        }
        if(!ok) continue;

        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                if (i == j) continue;
                if(abs(ord[i] - ord[j]) == abs(i - j)) ok = false;
            }
        }   
        
        if (ok){
            cout << "8 Queens" << endl;
            for(int i = 0; i < 8; i++){
                Y[i] = i;
                X[i] = ord[i];
            }
        }
    } while (next_permutation(ord.begin(), ord.end()));
    display();
    return 0;   
}