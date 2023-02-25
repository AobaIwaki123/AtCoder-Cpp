#include<iostream>
using namespace std;

int H,W;
std::string s[100];
char maze;

int main()
{
    cin >> H >> W;
    int start;
    for(int i = 0; i < H; i++)
    {
        cin >> s[i] >> maze;
        for(int j = 0; j < W; j++)
        {
            if(maze[j] == "S") start = {i,j};
        }
    }
    return 0;
}