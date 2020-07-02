#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n ; cin >> n ;
    map< string, int > requests;

    for (int i =0 ; i < n ; i ++)
    {
        string s; cin >> s;

        if(requests[s] > 0)
        {
            cout << s << requests[s] << endl;
            requests[s] ++ ;
        }
        else
        {
            requests[s] = 1 ;
            cout << "OK" << endl;
        }
    }


    return 0;
}
