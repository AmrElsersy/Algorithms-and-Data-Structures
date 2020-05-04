#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n , m ; cin >> n >> m ;
    vector<int> a (n);

    for(int i =0; i < n; i++)
        cin>>a[i];

    vector<int> distinct(100010,0); // for the position itself
    map<int,int> num_count; // to calculate how many times this number appears
    long long int cnt = 0;

    // dynamic programming
    for(int i =n-1 ; i >= 0 ; i--)
    {
        int flag_pos_distincit = 0;
        num_count[a[i]] ++;

        if(num_count[a[i]] == 1) // if it is the first time
        {
            flag_pos_distincit = 1;
        }

        // each position has a distincit values after it = (the same of i+1) or ( value(i+1) + 1 === this 1 of the value(i) itslef)
        distinct[i] = distinct[i+1] + flag_pos_distincit ;
    }

    for(int i =0; i < m ; i++)
    {
        int l ; cin >> l;
        cout <<distinct[l-1] << endl;
    }


    return 0;
}
