#ifndef STREET_PARADE_H
#define STREET_PARADE_H
#include "my_stl.h"

void StreetParade()
{
    int n; cin >> n ;
    stack<int> side_street ;
    stack<int> right_street;
    queue<int> left_street;

    for (int i =0 ; i< n ; i++)
    {
        int car ; cin >> car;
        left_street.push(car);
    }
    int _ ; cin >> _;

    int left=0,right=0,side=left_street.front();
    left_street.pop();
    for (int i =0 ; i < n ; i++)
    {
        if (!side_street.empty()) {side = side_street.top();} else {side = 0;}
        if (!right_street.empty()) {right = right_street.top();} else {right = 0;}
        if (!left_street.empty()) {left =  left_street.front();} else {left = 0;}
        if(side > right && side < left)
        {
            right_street.push(side);
            side_street.pop();
        }
        else if (side > right && side > left)
        {
            if (left - right == 1){
                right_street.push(left);
                left_street.pop();
            }
            else
            {
                side_street.push(left);
                left_street.pop();
            }
        }

    }

    while (!right_street.empty()) {
        cout << right_street.top() << " " ;
        right_street.pop();
    }
    cout << endl;

}


#endif // STREET_PARADE_H
