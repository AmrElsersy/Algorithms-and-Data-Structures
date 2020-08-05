#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Trie
{
public:
    Trie()
    {
        // root
        edges.push_back(map<char,int> ());

        int n ; cin >> n;
        for (int i =0; i < n ; i++)
        {
            string s ; cin >> s;
            this->AddPattern(s);
        }

        for (size_t i = 0; i < edges.size(); ++i)
            for (const auto & j : edges[i])
                std::cout << i << "->" << j.second << ":" << j.first << "\n";
    }

    void AddPattern(string s)
    {
        int current = 0;
        for (int i =0 ; i < s.size(); i++)
        {
            if (edges[current].count(s[i]) == 0)
            {
                edges.push_back( map<char,int>() );
                int index = edges.size() -1 ;
                edges[current][  s[i]  ] = index;
            }
            current = edges[current][ s[i] ];
        }
    }

private:
    vector< map<char,int> > edges;
};


int main()
{
    Trie trie;
    return 0;
}
