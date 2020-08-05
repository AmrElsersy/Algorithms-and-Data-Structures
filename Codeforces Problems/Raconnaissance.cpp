#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n ; cin >> n ;
    vector<int> heights(n) ;
    for (int i =0 ; i < n ; i++ ) cin >> heights[i] ;

    int first= 0+1,sec = n-1+1 ;
    int min= abs(heights[0]-heights[heights.size()-1]);
    for (int i =0 ; i < n-1 ; i ++)
    {
            int diff = abs(heights[i]-heights[i+1]);
            if( diff < min)
            {
                min = diff;
                first = i+1;
                sec = i+2;
            }
    }
    cout << first << " " << sec << endl;

    return 0;
}
