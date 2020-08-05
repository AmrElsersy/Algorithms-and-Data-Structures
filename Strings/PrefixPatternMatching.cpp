#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> Prefix(string s)
{
// https://www.coursera.org/learn/algorithms-on-strings/lecture/5lDsK/computing-prefix-function

    vector<int> prefix(s.size());
    prefix[0] = 0; // first element alyaws = 0;
    int border = 0; // border that will compare with

    for (int i = 1; i < s.size(); i++)
    {
        // move the border to the left till you find a match char between the border and the current char
        while (border > 0 && s[i] != s[border])
            border = prefix[border-1];// msh fahmha

        // if the reson we break the while is the 2nd one, so we have prefix matching just before our current char
        // so we increase the prefix matching with 1 and continue
        if (s[i] == s[border])
            border++;
        else
            border = 0;

        prefix[i] = border;
    }
    return prefix;
}

vector<int> PatternMatchingPos(string s, string p)
{
    // make string of pattern $ text
    // $ for prefix, to limit its value to the value of the lenght of the pattern
    // and if == pattern length, then this is a position of accurance of pattern, as it there is a repeated length chars
    string prefix_s = p + '$' + s;
    auto prefix = Prefix(prefix_s);
    vector<int> pos;
    for (int i = 0 ; i < prefix.size(); i ++)
    {
        if (prefix[i] == p.size())
        // because i is the end of the pattern matching
        // so begin = i - length - (length before $)
            pos.push_back(i - 2*p.size());
    }
    return pos;
}

int main()
{
    string s; cin >> s;
    string p; cin >> p;

    auto pos = PatternMatchingPos(s, p);
    for (int i =0; i < pos.size(); i ++)
        cout << pos[i] << " ";
        cout << endl;

    return 0;
}
