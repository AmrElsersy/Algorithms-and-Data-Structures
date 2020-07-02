#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    map<string,string> book;
    for (int i = 0; i < n; i++)
    {
        string s, num, name;
        cin >> s;
        if (s == "add")
        {
            cin >> num >> name;
            book[num] = name;
        }
        else if (s == "del")
        {
            cin >> num;
            book.erase(num);
        }
        else if (s == "find")
        {
            cin >> num;
            if (book.count(num))
                cout << book[num] << endl;
            else
                cout << "not found" << endl;
        }
    }
    return 0;
}
