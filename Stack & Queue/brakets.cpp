#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool checkBracket(char c)
{
    if (c == '{' || c == '}'|| c == '('|| c == ')'|| c == '['|| c == ']')
        return true;
    return false;
}

char opposite(char x)
{
    if (x == ')')
        return '(';
    else if (x==']')
        return '[';
    else if (x=='}')
        return '{';
    else if (x == '(')
        return ')';
    else if (x=='[')
        return ']';
    else if (x=='{')
        return '}';
}

int main()
{
    string s;
    cin >> s;

    deque<pair<char,int>> brackets;

    for (int i =0 ;i < s.size(); ++i)
    {
        if (!checkBracket(s[i]))
            continue;

        char c = s[i];
        if (c == '(' || c == '[' || c == '{')
        {
            pair<int,int> x ; x.first = c; x.second=i;
            brackets.push_back(x);
        }
        else if (c==')' || c == ']' || c =='}' )
        {
            if (brackets.empty())
            {
                cout << i+1 << std::endl;
                return 0;
            }
            if ( brackets.back().first != opposite(c) )
            {
                cout << i+1 << std::endl;
                return 0;
            }
            else
            {
                brackets.pop_back();
            }
        }
    }
    if (brackets.empty())
    {
        cout << "Success" << endl;
        return 0;
    }
    else
    {
        cout << brackets.front().second + 1 << endl;
        return 0;
    }

    return 0;
}
