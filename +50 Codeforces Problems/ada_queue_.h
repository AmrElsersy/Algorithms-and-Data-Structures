#ifndef ADA_QUEUE__H
#define ADA_QUEUE__H

#include <QtCore/QCoreApplication>
#include "my_stl.h"
list<int> query;

void operation(string op , int n = 0)
{
    if (op == "back")
    {
        if (query.empty())
        {
            cout << "No job for Ada?" << endl;
            return;
        }
        cout << query.back() << endl;
        query.pop_back();
    }
    else if (op == "front")
    {
        if (query.empty())
        {
            cout << "No job for Ada?" << endl;
            return;
        }
        cout << query.front() << endl;
        query.pop_front();
    }
    else if (op == "reverse")
    {
        query.reverse();
    }
    else if (op == "push_back")
    {
        query.push_back(n);
    }
    else if (op == "toFront")
    {
        query.push_front(n);
    }

}

void Ada_Queue()
{
    int queries = 0 ; cin >> queries;
    string current_query[queries];

    for (int i =0 ;  i < queries ; i++)
    {
        getline(cin ,current_query[i] );
        if (current_query[i] == "")
            i--;
    }
//    cout << "===========================" << endl;
//    for (int i =0 ;  i < queries ; i++)
//        cout << current_query[i] << endl;
//    cout << "===========================" << endl;
    for (int i = 0 ; i < queries ; i++)
    {
        if (current_query[i].length() <= 7) // for "front" ,  "back"
            operation(current_query[i]);

        else {
            int pos = current_query[i].find_first_of(" ") +1 ;
            string op = current_query[i].substr(0 , pos -1);
            int N = stoi( current_query[i].substr(pos , current_query[i].length() - pos) ) ;
            operation(op , N);
        }
    }
}

#endif // ADA_QUEUE__H
