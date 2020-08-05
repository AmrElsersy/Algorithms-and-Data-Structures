#ifndef COMMAND_LINE_H
#define COMMAND_LINE_H
#include "my_stl.h"

void command()
{
    uint n ; cin >> n;
    vector<string> commands;
    string current_directory;
    for (uint i =0 ; i< n; i++)
    {
        string s ; cin >> s;
        string s2 = "";
        if (s=="cd")
        {
           cin >> s2;

           vector<string> x = split_string(s2,"/");
           for (uint j = 0; j < x.size(); ++j) {
              if(x[j] == "..")
              {
                  current_directory = commands.back();
                  commands.pop_back();
              }
              else {
                  commands.push_back(x[i]);
              }
           }
        }
        else if (s == "pwd")
        {
            current_directory = commands.back();
            for (uint k = 0; k < commands.size();k++) {
                cout << commands[k] ;
                if(k!= commands.size() -1)
                    cout << "\\";
            }
            cout << endl;


        }
    }


}


#endif // COMMAND_LINE_H
