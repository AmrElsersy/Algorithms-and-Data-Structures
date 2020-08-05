#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class edge
{
public:
    map<char, int> childs;
    bool isPatternEnd = false;
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

        int n ; cin >> n;
        for (int i =0; i < n ; i++)
        {
            string s ; cin >> s;
            this->AddPattern(s);
        }

        checkSuffixes(text);
    }

    void AddPattern(string s)
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
            current = edges[current].childs[ s[i] ];
        }
        edges[current].isPatternEnd = true;
    }

    void calculatePatternPositions(string s,vector<int> &indexes, int pos)
    {
        int current = 0;
        for (int i =pos ; i < s.size(); i++)
        {
                char c = s[i];

                // we reach a leaf, or we didn't find the pattern(we are in the middle of the pattern that dosn't match the text char)
                // we will know which of them from the condition after the loop
                if (edges[current].childs.count(c) == 0)
                    break; // could be return,
                // if we find a char in the childs then continue searching in the patterns
                if (edges[current].childs.count(c) > 0)
                    current = edges[current].childs[c];
        }
         if (edges[current].childs.size() == 0)
            indexes.push_back(pos);
    }

    void checkSuffixes(string text)
    {
        vector<int> indexes;
        for (int i =0 ; i < text.size(); i++)
            calculatePatternPositions(text, indexes, i);

        for (int i =0 ; i < indexes.size(); i++)
            cout << indexes[i] << " " ;
        cout << endl;
    }

private:
    vector< edge > edges;
};


int main()
{
    Trie trie;
    return 0;
}
