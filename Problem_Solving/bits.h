#ifndef BITS_H_INCLUDED
#define BITS_H_INCLUDED
#include <bits/stdc++.h>
using namespace std;

void bits()
{
    int x = 0;
    int n ;
    cin >> n ;

    vector<string> operations(n) ;
    for(int i =0 ; i < n ; i ++)
        cin >> operations[i];

    for (int i =0 ; i < n ; i++)
    {
        int pos_plus = operations[i].find("++");
        int pos_minus = operations[i].find("--");

        if (pos_plus >= 0 )
            x ++;
        else if (pos_minus >= 0 )
            x --;
    }
    cout << x;
}


#endif // BITS_H_INCLUDED
