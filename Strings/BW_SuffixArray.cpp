#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Suffix
{
public:
    string s;
    int pos;
};

string BW_Transform(string s)
{
    s+= '$';
    vector<Suffix> matrix;
    // rotation
    for (int i = 0 ; i < s.size(); i++)
    {
        string s2 = s.substr(i);
        string s1 = s.substr(0, s.size() - s2.size() );

        Suffix suffix;
        suffix.s = s2;
        suffix.pos = s1.size();

        matrix.push_back(suffix);
    }

    sort(matrix.begin(), matrix.end(), [&](Suffix &s1, Suffix &s2)
    {
        return s1.s < s2.s;
    });

    for (int i = 0; i < matrix.size(); i++)
        cout << matrix[i].pos << " , " << matrix[i].s << endl;
}


int main()
{
    string s; cin >> s;
    cout << BW_Transform(s) << endl;
    return 0;
}
