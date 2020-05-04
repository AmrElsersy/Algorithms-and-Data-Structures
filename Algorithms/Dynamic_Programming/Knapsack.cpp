#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int w, n ; cin >> w >> n ;
    vector<int> bars (n);
    for(int i =0 ; i < n ; i ++)
        cin >> bars[i];

    vector< vector<int> > dp (n+1 , vector<int> (w+1) );
    for(int i =0 ; i <= n; i ++)
    {
        for(int j = 0 ; j <= w; j++)
        {
            if( i == 0 || j == 0 )
            {
                dp[i][j] = 0;
            }
            else if (j >= bars[i-1])
            {
                dp[i][j] = max( dp[i-1][j] , bars[i-1] + dp[i-1][ j- bars[i-1] ] );
            }
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    cout << dp[n][w] << endl;

    return 0;
}
