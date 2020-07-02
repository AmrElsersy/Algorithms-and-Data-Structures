#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("katryoshka.in","r",stdin);
    int T ; cin >> T ;
    int eyes , mouths , bodies ;
    for(int t = 0; t < T ;  t ++)
    {
        cin >> eyes >> mouths >> bodies ;
        int n  = 0 ;

        int m = min(eyes,mouths);
        m = min(m,bodies);
        eyes -= m ; mouths -= m ; bodies -= m ;
        n += m;
        while(true)
        {
            if (eyes > 1 && bodies)
            {
                eyes -= 2; bodies--;
                n ++;
            }
            else
                break;
        }

        cout << "Case " << t+1  << ": " <<  n << endl;
    }

    return 0;
}
