#include <bits/stdc++.h>
using namespace std;

int m,d;

int main()
{
    cin >> m >> d;
    if(m == 1 && d == 1) cout << "Yes" << endl;
    else if(m == 1 && d == 11) cout << "Yes" << endl;
    else if(m == 2 && d == 2) cout << "Yes" << endl;
    else if(m == 2 && d == 22) cout << "Yes" << endl;
    else if(m == d) cout << "Yes" << endl;
    else if(m == 11 && d == 1) cout << "Yes" << endl;
    else if(m == 11 && d == 11) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}