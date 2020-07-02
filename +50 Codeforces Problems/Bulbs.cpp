#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n , m ;  cin >> n >> m;
    set<int> ray2;
    for (int i =0 ; i < n ; i ++)
    {
        int x; cin >> x ;
        for (int j = 0 ; j < x;  j ++)
        {
            int y ; cin >> y;
            ray2.insert(y);
        }
    }


    if( ray2.size() < m )
    {
        cout << "NO" << endl;
        return 0;
    }
    else
        cout << "YES" << endl;

    return 0;
}
