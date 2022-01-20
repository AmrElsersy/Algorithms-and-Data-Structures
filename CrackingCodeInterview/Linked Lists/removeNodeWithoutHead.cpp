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

void deleteNode(ListNode* node) {

    auto it = node->next;
    auto last = node;
    while (it != nullptr)
    {
        node->val = it->val;
        last = node;
        it = it->next;
        node = node->next;
    }

    last->next = nullptr;
    delete node;
}

int main()
{
    auto n1 = new ListNode(1);
    auto n11 = new ListNode(2);
    auto n111 = new ListNode(3);
    auto n2 = new ListNode(4);
    auto n22 = new ListNode(5);
    auto n3 = new ListNode(6);
    auto n4 = new ListNode(7);


    n1->next = n11;
    n11->next = n111;
    n111->next = n2;
    n2->next = n22;
    n22->next = n3;
    n3->next = n4;

    deleteNode(n3);
    auto head = n1;
    while (head != nullptr)
    {
        cout << head->val << " - ";
        head = head->next;
    }
    cout << endl;
    return 0;
}
