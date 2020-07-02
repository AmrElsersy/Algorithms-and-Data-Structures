#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    Node* left;
    Node* right;
    int data;

    Node() {
        this->left = NULL;
        this->right = NULL;
    }
};

class BST {
public:
    Node* head ;
    BST () {this->head = NULL;}
    void insert(int insertedData)
    {
        if(this->head == NULL)
        {
            this->head= new Node();
            this->head->data = insertedData;
            return ;
        }

        Node* it = this->head ;
        while(it != NULL) // while true will work , not null for protection
        {
            if(insertedData > it->data )
            {
                if(it->right == NULL)
                {
                    // create node
                    Node* temp = new Node();
                    temp->data = insertedData;
                    // connect it
                    it->right = temp;
                    return;
                }
                else
                    it = it->right;
            }
            else
            {
                if(it->left == NULL)
                {
                    // create node
                    Node* temp = new Node();
                    temp->data = insertedData;
                    // connect it
                    it->left = temp;
                    return;
                }
                it = it->left;
            }
        }
    }

    Node* search(int searchedData)
    {
        Node* it = this->head;
        while(it != NULL) {
            if(it->data == searchedData )
                return it;
            else if ( searchedData > it->data )
                it = it->right;
            else if ( searchedData < it->data )
                it = it ->left;
        }
        return NULL;
    }

    int getDepth(Node* it )
    {
        if (! it)
            return 0;
        else if (!it->right && !it->left)
            return 1;

        int l = getDepth(it->left);
        int r = getDepth(it->right);

        int depth = max(l,r);
        depth++; // for the current node
        return depth;
    }

    bool isBalanced(Node* it)
    {
        if(!it) return true;
        int r = (it->right) ? this->getDepth(it->right) : 0;
        int l = (it->left) ? this->getDepth(it->left) : 0;
        if( abs(l-r) < 2 && isBalanced(it->right) && isBalanced(it->left) )
            return true;
        return false;
    }
};

int main()
{
        BST tree;
        int n ; cin >> n ;
        for(int i =0 ; i < n ;i ++)
        {
            int x ; cin >> x;
            tree.insert(x);
        }
        if(tree.isBalanced(tree.head))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
}
