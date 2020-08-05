#ifndef SHIP_SINK_SOLUTION2_H
#define SHIP_SINK_SOLUTION2_H
#include "my_stl.h"

enum prioriy { rat , woman , child , man , captin };

bool comapre(pair<string,prioriy> x,pair<string,prioriy> y)
{
    if(x.second < y.second)
        return true;
    return false;

}

prioriy check(string x)
{
    if (x == "woman")
        return woman;
    else if (x == "rat")
        return rat;
    else if (x == "child")
        return child;
    else if (x == "man")
        return man;
    else if (x == "captain")
        return captin;
}
void ship2()
{
    int n ; cin >> n ;
    vector<pair<string,prioriy>> people;
    for (int i = 0; i < n; ++i) {
        string name; cin >> name;
        string job; cin >> job;
        pair<string,prioriy> x ; x.first=name; x.second=check(job);
        people.push_back(x);
    }
    sort(people.begin(),people.end(),comapre);

    for (uint8_t i = 0 ;i< people.size(); i++)
        cout << "(" << people[i].first << "," << people[i].second << ")" << " ";
    cout << endl;
}

#endif // SHIP_SINK_SOLUTION2_H
