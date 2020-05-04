#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
//        int avarage = ( currentScoredGoals + neededGoals ) / (currentPlayed + currentRemain);
    freopen("mosalah.in","r",stdin);
    int T ; cin >> T ;
    for(int t = 0; t < T ;  t ++)
    {
        int last_GoalsPerMatch , currentScoredGoals , currentPlayed, currentRemain;
        cin >> last_GoalsPerMatch >> currentScoredGoals >> currentPlayed >> currentRemain;


        int neededGoals = last_GoalsPerMatch * (currentPlayed + currentRemain) - currentScoredGoals;

        if (    (currentRemain == 0 && neededGoals > 0) )
             neededGoals = -1;
        else if (neededGoals <= 0)
              neededGoals = 0;



        cout << neededGoals ;
        if(t < T-1)
            cout << endl;
    }

    return 0;
}
