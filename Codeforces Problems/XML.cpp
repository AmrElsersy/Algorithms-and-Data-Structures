#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#include <string>

string getTag(string s, bool open) {
    if(open) {
        return s.substr(1,s.size()-2);
    }
    else {
        return s.substr(2,s.size()-3);
    }
}
int main()
{
    int n ; cin >> n ;
    stack<string> tags;
    for (int i =0 ; i < n ; i ++)
    {
        string s; cin >> s;
        // if it is a tag
        if (s.size() > 2)
        {   
            // open tag
            if(s[0] == '<' && s[1] != '/' )
            {
                tags.push( getTag(s,true) );
            }
            // closing tag
            else if(s.substr (0,2) == "</" )
            {
                if(tags.empty())
                {
                    cout << "NO" << endl;
                    return 0;
                }
                if(tags.top() == getTag(s,false) )
                {
                    tags.pop();
                }
                else
                {
                    cout << "NO" << endl;
                    return 0;
                }

            }
            else {
                if( tags.empty())
                {
                    cout << "NO" << endl;
                    return 0;
                }
            }
        }
        // heading
        else {
                if( tags.empty())
                {
                    cout << "NO" << endl;
                    return 0;
                }
        }
    }
    if(tags.empty())
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
