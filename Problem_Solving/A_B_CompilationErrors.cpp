#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n ; cin >> n;
    vector<int> first(n);
    vector<int> second(n-1);
    vector<int> third(n-2);

    for(int i =0 ; i< n; i++)
        cin>>first[i] ;
    for(int i =0 ; i< n-1; i++)
        cin>>second[i] ;
    for(int i =0 ; i< n-2; i++)
        cin>>third[i] ;

    // sort them for comparing ray2
    sort(first.begin(),first.end());
    sort(second.begin(),second.end());
    sort(third.begin(),third.end());

    // put here the 2 solved errors
    vector<int> solved (2);

    int flag1,flag2 ; flag1=flag2=0;
    for(int i= 0 ; i < n-1 ; i++)
    {
        if(second[i] != first[i])
        {
            solved[0] = first[i];
            flag1=1;
            break;
        }
    }

    for(int i= 0 ; i < n-2 ; i++)
    {
        if(second[i] != third[i])
        {
            solved[1] = second[i];
            flag2=1;
            break;
        }
    }
    if(!flag1)
        solved[0] = first[n-1];
    if(!flag2)
        solved[1] = second[n-2];

    cout << solved[0] << endl;
    cout << solved[1] << endl;


    return 0;
}
