#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n , t ; cin >> n >> t;
    string que ; cin >> que;

    for (int i =0 ; i < t ; i ++)
    {
        for (int j =0; j < n ; j++)
        {
            if (que[j] == 'B' && que[j+1] == 'G' )
            {
                que[j+1] = 'B';
                que[j] = 'G';
                j++;
            }
        }
    }
    cout << que << endl;
    return 0;
}
