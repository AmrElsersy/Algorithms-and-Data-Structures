#include <bits/stdc++.h>
using namespace std;

string compressString(string s)
{
    if (s.size() == 1)
        return s;

    string compress;
    for (int i = 0; i < s.size()-1; i++)
    {
        int n_char = 1;
        while(s[i] == s[i+1])
        {
            n_char++;
            i++;
        }
        if (n_char == 1)
        {
            compress += s[i];
        }
        else if (n_char > 1)
        {
            compress += s[i];
            compress += to_string(n_char);
        }
    }

    // last char
    int last = s.size()-1;
    if (s[last] != s[last-1])
        compress += s[last];

    return compress;
}

int main()
{
    string s1 = "aaabbbbbbccdaaaf";
    cout << compressString(s1) << endl;
    return 0;
}
