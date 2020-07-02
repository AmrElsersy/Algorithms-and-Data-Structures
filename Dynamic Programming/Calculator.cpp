#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n ; cin >> n ;

    vector<int> arr;
    while (n >= 1)
    {
        arr.push_back(n);
        if (n%3 ==0 )
        {
            n = n/3;
        }
        else if (n%2 == 0)
        {
            n = n/2;
        }
        else
        {
            n --;
        }
    }
    cout << arr.size() -1 << endl;
    for(int i =arr.size()-1 ; i >= 0 ; i--)
        cout << arr[i] << " " ;
    cout << endl;

    return 0;
}
