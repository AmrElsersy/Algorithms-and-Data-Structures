#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{


    int n ; cin >> n ;
    map<int,int> friends;

    for(int i =1 ; i <= n ; i++)
    {
        int x ; cin >> x ;
        friends[x] = i;
    }
    for (int i =1 ; i <= n ; i ++)
    {
        cout << friends[i] << " " ;
    }
    cout << endl;


    return 0;
}
