#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void coins()
{
    int n ; cin >> n;
    int coin = 0;
    while  (n >= 10)
    {
        coin ++ ;
        n -= 10;
    }
    while  (n >= 5)
    {
        coin ++ ;
        n -= 5;
    }
    while  (n >= 1)
    {
        coin ++ ;
        n -= 1;
    }
    cout << coin << endl;
}

