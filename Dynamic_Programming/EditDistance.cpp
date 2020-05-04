#include <iostream>
#include <bits/stdc++.h>

using namespace std;



int editDistance(string str1, string str2, int m, int n) {
	vector<vector<int>> dp(m + 1, vector<int>(n + 1));

	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == 0)
				dp[i][j] = j;

			else if (j == 0)
				dp[i][j] = i;

			else if (str1[i - 1] == str2[j - 1])
				dp[i][j] = dp[i - 1][j - 1];

			else
				dp[i][j] = 1 + min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]);
		}
	}

	return dp[m][n];
}

int main()
{
    string a,  b;  cin >> a >> b;
    cout << editDistance(a,b, a.size(),b.size()) << endl;
    return 0 ;
}
/*
int main()
{
    string s1 , s2 ; cin >> s1 >> s2 ;


    vector<vector<int>> arr(s1.size() + 1, vector<int>(s2.size() + 1));


    for(int i =0 ; i <= s1.size(); i++)
        arr[i][0] = i;
    for(int i =0 ; i <= s2.size(); i++)
        arr[0][i] = i;

    for (int i =0 ; i <= s1.size() ; i ++)
    {
        for(int j= 0; j <= s2.size() ; j++ )
        {
            int insertion = arr[i][j-1] + 1 ;
            int deletion  = arr[i-1][j] + 1 ;
            int match = arr[i-1][j-1];
            int dismatch = match + 1;

            int ray2 = min (insertion,deletion);
            if( s2[i] == s1[j])
                arr[i][j] = min( ray2 , match);
            else
                arr[i][j] = min( ray2 , dismatch);
        }
    }

    cout << arr[s1.size()][s2.size()] << endl;
    return 0;
}
*/
