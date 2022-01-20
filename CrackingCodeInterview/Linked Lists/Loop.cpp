#include <bits/stdc++.h>
using namespace std;

class ListNode {
 public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* Loop(ListNode *head)
{
    // store pointers inside map to check intersection
    map<ListNode*, bool> nodeMap;

    // store just one of the lists
    auto it = head;
    while (it != nullptr)
    {
        if (nodeMap.count(it))
            return it;
        nodeMap[it] = true;
        it = it->next;
    }
    return nullptr;
}

int main()
{
    auto n1 = new ListNode(1);
    auto n11 = new ListNode(2);
    auto n111 = new ListNode(3);

    auto n2 = new ListNode(4);
    auto n22 = new ListNode(5);
    auto n222 = new ListNode(6);

    n1->next = n11;
    n11->next = n111;

    n2->next = n22;
    n22->next = n222;
    n222->next = n11;

    cout << Loop(n1)->val << endl;
    return 0;
}
