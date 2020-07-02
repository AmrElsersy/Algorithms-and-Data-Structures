#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n ; cin >> n;
    map<int,int> arr ;
    for (int i =0 ; i < n ; i ++)
    {
        int x; cin >> x;
        arr[x] ++ ;
    }
    for(auto i = arr.begin() ; i != arr.end(); i++)
    {
        if ( i->second > n/2)
        {
            cout << 1 << endl;
            return 0;
        }
    }
    cout << 0 << endl;

    return 0;
}
