#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string BW_Transform(string s)
{
    vector<string> matrix;
    // rotation
    for (int i = 0 ; i < s.size(); i++)
    {
        string s2 = s.substr(i);
        string s1 = s.substr(0, s.size() - s2.size() );
        string rotation = s2 + s1;
        matrix.push_back(rotation);
    }

    sort(matrix.begin(), matrix.end());
    string last_column;

    for (int i = 0; i < matrix.size(); i++)
        last_column += matrix[i][matrix.size()-1];
    return last_column;
}


int main()
{
    string s; cin >> s;
    cout << BW_Transform(s) << endl;
    return 0;
}
