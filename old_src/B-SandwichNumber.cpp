#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
    string S;
    cin >> S;
    // 最初は数字でなければならない
    int tf = 0;
    for(int i = 0; i < S.size(); i++){
        if(i == 0){
            // 文字であれば加点
            if(isdigit(S[i]) == 0) tf ++;
        }
        // 範囲を指定するときは、&&か||を用いる
        else if(1 <= i && i <= 6){

            // 数字であるかを判定
            if(isdigit(S[i]) != 0){
                if(i != 1) tf ++;
                else{
                    int a = S[i] - '0';
                    if(a != 0) tf ++;
                }
            }
        }
        else if(i == 7){

            if(isdigit(S[i]) == 0) tf ++;
        }
    }
    if(tf == 8) cout << "Yes" << endl;
    else cout << "No" << endl;
}