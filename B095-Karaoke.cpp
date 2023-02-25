#include<iostream>
#include<cmath>
using namespace std;

int N,M;
int a[50];
int h[50][10];

int main()
{
    cin >> N >> M;
    for(int i = 0; i < M; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> h[i][j];
        }
    }
    int error, _point;
    int point = 0;
    for(int i = 0; i < N; i++){
        _point = 100;
        for(int j = 0; j < M; j++){
            error = abs(a[j] - h[i][j]);
            if(error <= 5) continue;
            else if(error <= 10) _point --;
            else if(error <= 20) _point -= 2;
            else if(error <= 30) _point -= 3;
            else _point -= 5;
        }
        if(_point > point) point = _point;
    }
    cout << point << endl;
    return 0;
}