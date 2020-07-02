#ifndef FOOTBALL_H_INCLUDED
#define FOOTBALL_H_INCLUDED
void football()
{

    string players ; cin >> players;
    int dangerous = 1 ;
    for (int i =0 ; i < players.size()-1 ; i ++)
    {
        if (players[i] == players[i+1])
            dangerous ++ ;
        else
            dangerous = 1 ;
        if (dangerous == 7)
        {
            cout << "YES";
            return 0 ;
        }
    }
    cout << "NO";
}


#endif // FOOTBALL_H_INCLUDED
