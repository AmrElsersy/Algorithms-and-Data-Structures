#include <iostream>
#include <bits/stdc++.h>
using namespace std;



void Salary()
{
    int n ; cin >> n ;
    vector<string> salaries(n);
    vector<char> all_chars;
    for(int i =0 ; i < n ;i ++)
    {
        string x ; cin >> x;
        salaries[i] = x;
        for(int i=0; i < x.size(); i++)
            all_chars.push_back(x[i]);
    }

    sort(all_chars.begin(),all_chars.end());
    string x;
    for(int i = all_chars.size()-1 ; i >= 0; i--)
    {
        x += all_chars[i];
    }

    cout << x << endl;

}






