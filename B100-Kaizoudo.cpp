#include<iostream>
using namespace std;

// 全問正解
int main(){
    int H,W;
    int I[2][300][300];
    int I2[599][599];

    // 入力の受け取り
    cin >> H >> W;
    for(int i = 0; i < 2; i++){
        
        for(int j = 0; j < H; j++){
            for(int k = 0; k < W; k++){
                cin >> I[i][j][k];
            }
        }
    }
    for(int i = 1; i <= 2*H-1; i++){
        for(int j = 1; j <= 2*W-1; j++){
            I2[i][j] = (I[0][i/2][j/2] + I[1][(i-1)/2][(j-1)/2])/2;
            cout << I2[i][j] << (j == 2*W-1 ? "\n" : " ");
        }
    }
    return 0;
}