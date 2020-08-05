#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    deque<int> conversations;
    map<int,int> conversationFound;

    int n , k ; cin >> n >> k ;
    for (int i =1 ; i <= n ; i ++)
    {
        int msg ; cin >> msg;

        int found = 0;
        try
        {
            found = conversationFound[msg] ;
        }
        catch( ... )
        {
            found = 0;
        }

        if ( found == 0 )
        {
            conversations.push_front(msg);
            conversationFound[msg] = 1;

            if(conversations.size() > k)
            {
                conversationFound[conversations[ conversations.size()-1] ] = 0;
                conversations.pop_back();
            }
        }
    }

    cout << conversations.size() << endl;
    for (int i = 0 ; i < conversations.size(); i++)
        cout << conversations[i] << " " ;
    cout << endl;


    return 0;
}
