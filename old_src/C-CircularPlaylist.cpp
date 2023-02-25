#include<iostream>
using namespace std;

int main(){
    long long N,T;
    long long A[100000];
    cin >> N >> T;
    long long sum = 0;
    for(int i = 0; i < N; i++){
        cin >> A[i];
        sum += A[i];
    } 
    T = T % sum;
    for(int i = 0; i < N; i++){
        if(T - A[i]< 0){
            cout << i+1 << " " << T << endl;
            return 0;
        }
        T = T - A[i];
    }
    return 0;
}