#include<iostream>
using namespace std;

long long N, K;
int main(void)
{
    long long A[200]= {0};
    cin >> N >> K;
    for(int i = 0; i < N; i++) cin >> A[i];

    for(int i = K; i < N + K; i++)
    {
        cout << A[i] << " ";
    }
    return 0;
}