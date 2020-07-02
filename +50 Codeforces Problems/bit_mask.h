#ifndef BIT_MASK_H
#define BIT_MASK_H
#include <utility>
#include <bits/stdc++.h>
#include "iostream"
using namespace std;

void Bacteria()
{
    uint x ; cin >> x;
    uint a = 1;
    int count =1;
    while (true)
    {
        if (a == x)
        {
            cout << count << endl;
            return;
        }
        else if (a < x)
        {
            a = a << 1;
        }
        else if (a > x)
        {
            a = a >> 1;
            a++;
            count ++;
        }

    }

}


#endif // BIT_MASK_H
