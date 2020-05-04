#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> arr;

void print(int l , int r)
{   if(l>r) return;
    for(int i =l ; i <= r; i++)
        cout << arr[i] << " " ;
    cout << endl;
}

int binarySearch( int l, int r, int x)
{
    while (l <= r) {
        int m = l + (r - l) / 2;

        if (arr[m] == x)
            return m;

        if (arr[m] < x)
        {
            l = m + 1;
            print(l,r);
        }
        else {
            r = m - 1;
            print(l,r);
        }
    }
    return -1;
}

int main()
{
    int x ; cin >> x ;
    int n ; cin >> n ;
    for (int i =0 ; i < n ; i++)
    {
        int z ; cin >> z ;
        arr.push_back(z);
    }

    int s = binarySearch(0,arr.size()-1, x);
    if(s == -1)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;



    return 0;
}
