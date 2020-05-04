#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string x1,x2;
    cin >> x1 >> x2;
    int n = x1.size();

    for (int i =0 ; i < n ; i ++)
    {
        x1[i] = tolower(x1[i]);
        x2[i] = tolower(x2[i]);
    }
    if (x1 < x2)
        cout << -1;
    else if ( x2 < x1 )
        cout << 1 ;
    else
        cout << 0;

    return 0;
}
