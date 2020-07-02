#include <iostream>

using namespace std;

int main()
{
    string s ; cin >> s;
    if(s.size() < 3)
    {
        cout << s << endl;
        return 0;
    }

        // check for 3 repeated char
    for (int i =0 ; i < s.size() -2; i++)
    {

        if(s[i] == s[i+1] && s[i+1] == s[i+2])
        {
            s.erase(i,1);
            i --;
        }
    }

    if(s.size() < 4)
    {
        cout << s ;
        return 0;
    }

    for(int i =0 ; i < s.size()-3 ; i++)
    {
        if(s[i] == s[i+1] && s[i+2] == s[i+3])
        {
            s.erase(i+2,1);
            i--;
        }
    }

    cout << s;


    return 0;
}
