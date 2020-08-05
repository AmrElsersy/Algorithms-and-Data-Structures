#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class edge
{
public:
    map<char, int> childs;
    set<int> startIndex;
};

class Trie
{
public:
    Trie()
    {
        // root
        edges.push_back(edge());

        string text;
        cin >> text;
        BuildSuffixes(text);

        int n ; cin >> n;

        for (int i =0; i < n ; i++)
        {
            string pattern ; cin >> pattern;
            SetPatternPos(pattern);
        }

        for (auto it = this->pos.begin(); it != this->pos.end(); it++)
            cout << *it << " ";
    }

    void BuildSuffixes(string s)
    {
        for (int i =0; i < s.size(); i++)
            AddSuffix(s.substr(i), i);
    }

    void AddSuffix(string s, int startPos)
    {
        int current = 0;
        for (int i =0 ; i < s.size(); i++)
        {
            if (edges[current].childs.count(s[i]) == 0)
            {
                edges.push_back( edge() );
                int index = edges.size() -1 ;
                edges[current].childs[  s[i]  ] = index;
            }
            edges[current].startIndex.insert(startPos);
            current = edges[current].childs[ s[i] ];
        }
        if (current < edges.size())
            edges[current].startIndex.insert(startPos);
    }

    void SetPatternPos(string s)
    {
        int current = 0;
        for (int i =0 ; i < s.size(); i++)
        {
                char c = s[i];

                if (edges[current].childs.count(c) == 0)
                    return ;

                if (edges[current].childs.count(c) > 0)
                    current = edges[current].childs[c];
        }

        this->pos.insert(edges[current].startIndex.begin(), edges[current].startIndex.end());
        for (auto child : edges[current].childs)
            this->pos.insert(edges[ child.second ].startIndex.begin(),
                             edges[ child.second ].startIndex.end());
    }


private:
    vector< edge > edges;
    set<int> pos;
};


int main()
{
    Trie trie;
    return 0;
}
