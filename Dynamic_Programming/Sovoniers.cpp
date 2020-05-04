#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n ; cin >> n ;
    vector<int> arr(n);
    int sum = 0;
    for(int i =0 ; i < n ; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    if(sum % 3 != 0 || n <3 )
    {
        cout << 0 << endl;
        return 0;
    }
    int third = sum /3 ;

    vector< vector<int> > dp ( n+1 , vector<int> (third+ 1,0) );
    for(int i =0 ; i <=n ; i++)
        dp[i][0] = 1;

    for(int i = 1; i <= n ; i ++)
    {
        for (int j =1 ; j <= third; j++)
        {
            if( j < arr[i])
            {
                dp[i][j] = dp[i-1][j];
            }
            else
            {
                dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i]];
            }
        }
    }

    cout << dp[n][third] << endl;










    return 0;

}
