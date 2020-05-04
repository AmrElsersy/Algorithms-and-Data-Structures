#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a ; cin >> a ;
    vector<int> A(a);
    for(int i =0 ; i < a; i++)
        cin >> A[i];
    int b ; cin >> b ;
    vector<int> B(b);
    for(int i =0 ; i < b; i++)
        cin >> B[i];


    vector< vector<int> > arr (a+1 , vector<int>(b+1) );
    for(int i =0 ; i <= a ; i++)
    {
        for(int j =0 ; j<= b; j++)
        {
            // initialization
            if (i == 0 || j == 0)
                arr[i][j] = 0;
            else if (A[i-1] == B[j-1])
                arr[i][j] = arr[i-1][j-1] + 1 ;
            else
                arr[i][j] = max(arr[i-1][j] , arr[i][j-1]);
        }
    }
    cout << arr[a][b] << endl;;


    return 0;
}
