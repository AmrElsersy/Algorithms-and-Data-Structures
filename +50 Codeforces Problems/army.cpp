#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n ; cin >> n ;
    vector<int> d (n-1);
    for (int i =0 ; i < n-1 ; i ++)
        cin >> d[i];
    int a,b; cin >> a >> b;
    // ...............
    int range = b-a;
    int output = 0;
    for (int i =a ; i < b; i++)
        output += d[i-1];

    cout << output << endl;

    return 0;
}
