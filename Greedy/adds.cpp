#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void ads()
{
    int n ; cin >> n ;
    vector<long long> a(n); vector<long long> b(n) ;
    for (int i =0 ; i <n ; i ++)
        cin >> a[i];
    for (int i =0 ; i <n ; i ++)
        cin >> b[i];

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    long long profit= 0.0;
    for(int i =0 ; i<n ;i++)
    {
        profit += (long long)a[i] * (long long)b[i];
    }

    cout << profit << endl;
}



