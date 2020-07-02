#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num_cuts = 0;
    int n ; cin >> n;
    vector<int> abc(3); cin >> abc[0] >> abc[1] >> abc[2];
    sort(abc.begin(),abc.end());
    int a = abc[0] , b = abc[1] , c = abc[2] ;
    stack<int> cuts;

    num_cuts += n/a;
    n = n % a;
    if (n == 0 ) {cout << num_cuts ; return 0;}

    for(int i =0 ; i< num_cuts ; i++)
        cuts.push(a);

    while(n<b)
    {
        num_cuts--;
        n += cuts.top();
        cuts.pop();
    }

    num_cuts ++;
    n = n % b;
    if (n == 0 ) {cout << num_cuts ; return 0;}

    while (n<c)
    {
        num_cuts--;
        n += b;
    }
    num_cuts ++;
    n = n % c;

    if (n)

    cout << num_cuts;

    return 0;
}
