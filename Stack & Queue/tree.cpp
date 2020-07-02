#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class node {
public:
    int label;
    vector<node*> childs;
    void addChild(node *x) {this->childs.push_back(x);}
};

int Height(node* Node)
{
    int maxHeight = 0;
    for (int i =0 ; i < Node->childs.size(); ++i)
    {
        int height = Height(Node->childs[i]);
        if (height > maxHeight)
            maxHeight =  height;
    }
    return ++maxHeight;
}

void print(node* Node)
{
    cout << Node->label << "\t" << endl;
    for (int i =0 ; i < Node->childs.size(); ++i)
    {
        print(Node->childs[i]);
    }
    cout << endl;
}

int main()
{
    int n ; cin >> n ;

    vector<node> nodes(n);
    int parentNode;

    for (int i =0 ; i < n ; ++i)
    {
        int parent ; cin >> parent;

        if (parent == -1)
            parentNode = i;
        else {
            nodes[i].label = i;
            nodes[parent].addChild( & nodes[i] );
        }
    }

//    print(&nodes[4]);
    cout << Height(&nodes[parentNode]) << endl;

    return 0;
}
