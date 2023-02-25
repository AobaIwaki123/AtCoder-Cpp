#include<iostream>
using namespace std;

int N, K, A[101];

int main()
{
    cin >> N >>K;
    for(int i = 1; i <= N; i++)
    {
        cin >> A[i];
    }
    for(int loop = 1; loop <= K; loop++)
    {
        for(int i = 1; i <= N; i++)
        {
            A[i] = A[i+1];
        }
        A[N] = 0;
    }
    for(int i = 1; i <= N; i++)
    {
        // 最後なら改行、それ以外なら空白の処理
        cout << A[i] << (i == N ? "\n" : " ");
    }
}