#ifndef SINKING_SHIP_H
#define SINKING_SHIP_H

#include "my_stl.h"
void ship()
{
    int n ; cin >> n ;
    map<string,vector<string>> people;
    for (int i = 0; i < n; ++i) {
        string name; cin >> name;
        string job; cin >> job;
        vector<string> empty;
        people[job].push_back(name);
    }
    cout << endl;
    for (auto i = people.begin();i!= people.end();i++) {

    for (uint64_t j =0 ;j < i->second.size();j++)
        cout << i->second[j] << " ";
    cout << endl;
}

}

#endif // SINKING_SHIP_H
