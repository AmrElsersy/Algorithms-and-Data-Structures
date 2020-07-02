#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<string> split_string(string s,string splitter)
{
    vector<string> splitted;
    int n = s.length();
    int pos = 0;
    int start = pos;
    while (pos != string::npos)
    {
        pos = s.find(splitter,pos+1);
        string splitted_string = s.substr(start,pos-start);
        splitted.push_back(splitted_string);
        start = pos+splitter.size();
    }
    return splitted;
}

int main()
{
    string s; cin >> s;

    while(true)
    {
        int pos = s.find("WUB",0);
        if(pos == string::npos) break;
        s.replace(pos,3," ");
    }
    while(s[0] == ' ')
        s.erase(0,1);

    cout << s << endl;
}
