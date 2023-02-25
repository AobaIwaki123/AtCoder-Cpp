#include<iostream>
#include<vector>
#include<stdio.h>
#include<time.h>

using namespace std;

long long N,Q;
long long T[20000];
long long A[20000];
long long B[20000];

int main(void)
{
    cin >> N >> Q;
    for(int i = 0; i < Q; i++)
    {
        cin >> T[i] >> A[i] >> B[i];
    }
    std::vector<std::vector<int> > C(N+1,std::vector<int>(N+1,0));
    for(int i = 0 ; i < Q; i++)
    {
        if(T[i] == 1)
        {
            C[A[i]][B[i]] =1;
        }
        else if(T[i] == 2)
        {
            C[A[i]][B[i]] =0;
        }
        else if(T[i] == 3)
        {
            if(C[A[i]][B[i]] == 1 && C[B[i]][A[i]] == 1) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}