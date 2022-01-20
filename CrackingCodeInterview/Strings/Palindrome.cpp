#include <bits/stdc++.h>
using namespace std;

bool oneWay(string s1, string s2)
{
    int counts1[26] = 0;
    int counts2[26] = 0;

    for (auto c : s1)
        counts1[c-'a']++;
    for (auto c : s2)
        counts2[c-'a']++;


}

int main()
{
    string s1 = "Tact Coa";
    string s2;

    cout << oneWay(s1, s2) << endl;
    return 0;
}
