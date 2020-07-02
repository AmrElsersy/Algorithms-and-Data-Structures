#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n ; cin >> n ;
    int left = 0, right = 0;

    int shelf[1000000];

    for (int i =0 ; i < n ; i++)
    {
        char type ; int book;
        cin >> type >> book;

        if(type == 'L')
        {
            left --;
            shelf[book] = left;
        }
        else if (type == 'R')
        {
            right ++;
            shelf[book] = right;
        }
        else if (type == '?')
        {
            int ans;
            if(shelf[book] > 0 )
            {
                ans = min( abs(right - shelf[book]) , abs(shelf[book] - left) -1 );
            }
            else
            {
                ans = min( abs(right - shelf[book]) -1 , abs(shelf[book] - left)    ) ;
            }
            cout << ans << endl;
        }

    }

    return 0;
}
