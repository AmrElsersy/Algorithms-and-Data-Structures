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
        pos = s.find_first_of(splitter,pos+1);
        string splitted_string = s.substr(start,pos-start);
        splitted.push_back(splitted_string);
        start = pos+1;
    }

    return splitted;
}

int main()
{
    string x ; getline(cin,x);
    vector<string> s = split_string(x," ");
    stack<string> Stack;
    for (int i =0 ; i < s.size(); i++)
    {
        string z = s[i];
        if ( z == "+"  || z == "-" || z == "/"|| z == "*"|| z == "^")
        {
            if(Stack.size() < 2)
            {
                cout << "NO" << endl;
                return 0;
            }
            string top1 = Stack.top();  Stack.pop();
            string top2 = Stack.top();  Stack.pop();

            string notation = "("+  top2 + z + top1   +")" ;
            Stack.push(notation);

        }
        else if ( z== "tan")
        {
            if(Stack.empty())
            {
                cout << "NO" << endl;
                return 0;
            }
            string top = Stack.top();  Stack.pop();

            string notation = "("+  z + "(" + top + ")"    +")" ;
            Stack.push(notation);

        }
        else {
            Stack.push(z);
        }
    }
    while ( !Stack.empty()) {
        cout << Stack.top() << endl;
        Stack.pop();
    }
    return 0;
}
