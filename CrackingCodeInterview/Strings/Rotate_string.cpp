#include <bits/stdc++.h>
using namespace std;

string shiftString(string s1, int shift)
{
    string s11 = s1;
    for (auto &c : s11)
        c = ' ';

    for (int i =0; i < s1.size(); i++)
    {
        int newIndex = (i % s1.size() + shift) % s1.size();
        s11[newIndex] = s1[i];
    }
    return s11;
}
bool isRotate(string s1, string s2)
{
    for (int i = 0; i < s1.size(); i++)
    {
        string s11 = shiftString(s1, i);
        if (s11 == s2)
            return true;
    }
    return false;
}

int main()
{
    string s1 = "bbbacddceeb";
    string s2 = "ceebbbbacdd";
    cout << isRotate(s1, s2) << endl;
    return 0;
}
