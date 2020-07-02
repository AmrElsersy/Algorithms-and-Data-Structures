#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    float n , t , k , d ; cin >> n >> t >> k >> d;

    float speed = k / t;
    int time = n / speed ;
    int cakes = speed * (time-d);

    cout << speed << endl;
    cout << time << endl;
    cout << cakes << endl;


    if(cakes > 0 )
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
