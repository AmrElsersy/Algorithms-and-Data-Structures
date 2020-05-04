#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isPunctuation(char s)
{
    return (s == ',' || s== '?' || s== '.' || s== ';' || s== ':' || s== '"' || s== '!' );
}

int main()
{
    string s ; getline(cin,s);

    // spaces
    for (int i =0 ; i < s.size()-1; i ++)
    {
        if(s[i] == ' ' && s[i+1] == ' ')
        {
            s.erase(i,1);
            i--;
        }
        else if (s[i] == ' ' && isPunctuation(s[i+1]) )
         {
            char punctuation = s[i+1];
            s[i+1] = ' ';
            s[i] = punctuation;
        }
        else if (isPunctuation(s[i]) && s[i+1] != ' ')
        {
            s.insert(i+1," ");
        }
    }
    cout << s << endl;

    return 0;
}
