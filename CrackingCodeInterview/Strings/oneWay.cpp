#include <bits/stdc++.h>
using namespace std;

bool isReplace(string s1, string s2)
{
    bool isReplaced = false;
    for (int i = 0; i < s1.size(); i++)
    {
        if (s1[i] != s2[i])
        {
            if (!isReplaced)
                isReplaced = true;
            else
                return false;
        }
    }
    return true;
}

// s2 is the stirng to be shifted
bool isInsertRemove(string s1, string s2)
{
    // s1 size = x .. s2 size = x-1
    for (int i =0; i< s2.size(); i++)
    {
        if (s1[i] != s2[i])
        {
            s2.insert(i, " ");
            return isReplace(s1, s2);
        }
    }
    return true;
}

bool oneWayCheck(string s1, string s2)
{
    int size1 = s1.size();
    int size2 = s2.size();
    int delta = size1 - size2;

    if (size1 == size2)
        return isReplace(s1, s2);
    else if (delta == 1)
        return isInsertRemove(s1, s2);
    else if (delta == -1)
        return isInsertRemove(s2, s1);
    return false;
}

int main()
{
    string s1 = "apple";
    string s2 = "aple";
    cout << oneWayCheck(s1, s2) << endl;
    return 0;
}
