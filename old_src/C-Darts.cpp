#include<iostream>
#include<algorithm>
using namespace std;

long long N, M, P[100000000];

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++) cin >> P[i];
    
    sort(P, P+N);

    
    return 0;
}