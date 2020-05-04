#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int cnt[8] = {0};
    int n ; cin >> n ;
    for(int i =0 ; i< n ; i++)
    {
        int x ; cin >> x;
        cnt[x]++;
    }
    // if there is 5 or 7 , this will fail not ray2
    if(cnt[5] == 0 && cnt[7] == 0 && cnt[2] >= cnt[4] && cnt[1] == cnt[4] + cnt[6] && cnt[2] + cnt[3] == cnt[4]+ cnt[6])
    {
        for(int i = 0; i < cnt[4] ; i++)
            cout << "1 2 4" << endl;
        cnt[2] -= cnt[4] ; // as we used it cnt_4 times

        for(int i=0; i < cnt[2] ; i++)
            cout << "1 2 6" << endl;
        for(int i =0; i< cnt[3] ; i ++)
            cout << "1 3 6" << endl;

    }
    else
        cout << "-1" << endl;

    return 0;
}
