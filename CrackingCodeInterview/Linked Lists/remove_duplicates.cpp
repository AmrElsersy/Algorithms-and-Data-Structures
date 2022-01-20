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

ListNode* deleteDuplicates(ListNode* head) {
    if (!head)
        return head;
    map<int, int> counts;

    auto it = head;
    auto prevIt = it;

    counts[it->val] = 1;
    it = it->next;
    while (it != nullptr)
    {
        // if duplicated delete it
        if (counts.count(it->val))
        {
            ListNode *deletedNode = it;
            prevIt->next = it->next;
            it = it->next;
            delete deletedNode;
        }
        else
        {
            counts[it->val] = 1;
            prevIt = it;
            it = it->next;
        }
    }
    return head;
}

int main()
{
    auto n1 = new ListNode(1);
    auto n11 = new ListNode(1);
    auto n111 = new ListNode(1);
    auto n2 = new ListNode(2);
    auto n22 = new ListNode(2);
    auto n3 = new ListNode(3);
    auto n4 = new ListNode(4);
    auto n44 = new ListNode(4);
    n1->next = n11;
    n11->next = n111;
    n111->next = n2;
    n2->next = n22;
    n22->next = n3;
    n3->next = n4;
    n4->next = n44;

    auto head = deleteDuplicates(n1);
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
    return 0;
}
