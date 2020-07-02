#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void carFuel()
{
    int total_distance , car_distance , n; cin >> total_distance >> car_distance >> n;
    vector<int> stations(n);
    for (int i =0 ; i < n ; i++)
    {
        cin >> stations[i] ;
    }
    stations.push_back(total_distance);
    n++;

    int num = 0;
    int pos_car = 0;
    int i =0 ;
    while(pos_car < total_distance)
    {
        while( stations[i+1] - pos_car <= car_distance  && i+1 < n )
        {
            i++;
        }



        // if the position dosn't change
        if(pos_car == stations[i])
        {
            cout << -1 << endl;
            return;
        }
        if( i < n-1 )
            num++;
        pos_car = stations[i];
    }

    cout << num << endl;
}

