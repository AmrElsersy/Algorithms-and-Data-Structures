#ifndef REVERSE_STRING_H
#define REVERSE_STRING_H

#include "my_stl.h"

void reverse_string()
{
    string s ; cout << "enter: " << endl;
    getline(cin,s);
    cout << s << endl;
    cout << s << endl;
    vector<string> strs;
    int pos = s.find_first_of(" ",0);
    int start = 0;
    while (true)
    {
        pos = s.find_first_of(" ",pos+1);
        if (pos == -1)
        {
            string temp2 = s.substr(start);
            strs.push_back(temp2);
            break;
        }
        string temp = s.substr(start, pos -start);
        strs.push_back(temp);
        start = pos;
    }
    for (int i=0;i < strs.size();++i) {
        int n = strs[i].size();
        for (int j =0 ; j< n/2; j++) {
            int temp = strs[i][j];
            strs[i][j] = strs[i][n-j-1];
            strs[i][n-j-1] =temp;
        }
    }

    for (int i = 0; i < strs.size(); ++i) {
        cout << strs[i] <<" ";
    }
    cout << endl;

}


#endif // REVERSE_STRING_H
