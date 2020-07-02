#ifndef PARENTHESES_H
#define PARENTHESES_H
#include "my_stl.h"

bool is_opposite(char x , char y)
{
    if ( ( x == '(' && y == ')') ||  (x== '[' && y ==']' ))
        return true;
    return false;
}
void Parentheses()
{
    string s ; cin >> s;
    map<char,char> opposite;
    stack<char> x;

    opposite['('] = ')';
    opposite['['] = ']';
    x.push(s[0]);
    for (int i =1; i < s.length(); i++) {
        if (is_opposite(x.top(),s[i]) )
        {
            x.pop();
        }
        else
        {
            x.push(s[i]);
        }
    }
    if (x.empty())
    {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;


}

#endif // PARENTHESES_H
