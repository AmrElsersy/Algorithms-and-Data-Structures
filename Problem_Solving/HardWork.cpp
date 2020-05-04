#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void clean(string& s)
{
    for (int i =0 ; i < s.size(); i ++)
    {
        if(s[i] == ';' || s[i] == '-' || s[i] == '_')
        {
            s.erase(i,1);
            i--;
        }

        else if( isupper(s[i]) )
            s[i] = tolower(s[i]);

    }
}

bool compare(string x , string y )
{
    return ( x.size() < y.size() );
}

int main()
{
    string s1,s2,s3; cin >> s1 >> s2 >> s3 ;

    // remove the ay marks 8ariba (-,;,_ ) and make every letter is lower
    clean(s1);
    clean(s2);
    clean(s3);

    int n ; cin >> n;
    for (int i =0 ; i < n ; i ++)
    {
        string s; cin >> s;
        clean(s);

        int pos1= s.find(s1);
        int pos2= s.find(s2);
        int pos3= s.find(s3);

        if(pos1 == string::npos || pos2 == string::npos || pos3 == string::npos)
        {
            cout << "WA" << endl;
            continue;
        }

        if(s == s1+s2+s3 || s == s1+s3+s2 || s == s2+s1+s3 || s == s2+s3+s1 || s == s3+s1+s2 || s== s3+s2+s1)
        {
            cout << "ACC" << endl;
        }
        else
        {
            cout << "WA" << endl;
        }
    }


    return 0;
}
