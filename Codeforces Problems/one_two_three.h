#ifndef ONE_TWO_THREE_H
#define ONE_TWO_THREE_H

#include "sort2d.h"
string a5oh_el_r5m[3] = {"one" ,"two" , "three"};

int check(string s)
{
    int one = 0 , two = 0 , three= 0;

    if (s.length() == 3)
    {
        for (int j =0 ; j< 3 ; j++)
            if (s[j] != a5oh_el_r5m[0][j])
                one --;

        for (int k =0 ; k< 3 ; k++)
            if (s[k] != a5oh_el_r5m[1][k])
                two--;

        if (one == 0 || one == -1)
            return 1;
        else if (two == 0 | two == -1)
            return 2;
    }
    else if (s.length() == 5)
    {
        for (int m =0 ; m< 5 ; m++)
            if (s[m] != a5oh_el_r5m[2][m])
                three --;
        if (three == 0 || three == -1)
            return 3;
    }

}

int one_two_three()
{

    int n ; cin >> n ;
    vector<string> x(n);
    for (int i =0; i< n ; i++)
        cin >> x[i];
    for (int i =0; i< n ; i++)
    {
        int c = check(x[i]);
        cout << c << endl;
    }
}

#endif // ONE_TWO_THREE_H
