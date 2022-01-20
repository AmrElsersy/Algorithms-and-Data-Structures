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

ListNode* addNode(ListNode *head, int val)
{
    if (head == nullptr)
    {
        head = new ListNode(val);
        return head;
    }

    auto it = head;
    while(it->next != nullptr)
        it = it->next;

    auto newNode = new ListNode(val);
    it->next = newNode;
    return head;
}

int listSize(ListNode *head)
{
    auto it = head;
    int i = 0;
    while (it)
    {
        i++;
        it = it->next;
    }
    return i;
}

ListNode *padding(ListNode *head, int pad)
{
    auto it = head;
    while (it->next != nullptr)
        it = it->next;

    for (int i = 0; i < pad; i++)
    {
        auto newNode = new ListNode(0);
        it->next = newNode;
        it = newNode;
    }
    return head;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    ListNode *head = nullptr;
    int sizeL1 = listSize(l1);
    int sizeL2 = listSize(l2);

    if (sizeL1 != sizeL2)
    {
        int diff = abs(sizeL1 - sizeL2);
        if (sizeL1 > sizeL2)
            l2 = padding(l2, diff);
        else
            l1 = padding(l1, diff);
    }

    /*
    auto it = l1;
    while (it != nullptr)
    {
        cout << it->val << " - ";
        it = it->next;
    }
    cout << endl;
    it = l2;
    while (it != nullptr)
    {
        cout << it->val << " - ";
        it = it->next;
    }
    cout << endl;
    */

    auto it1 = l1;
    auto it2 = l2;

    int carry = 0;
    while (it1 && it2)
    {
        int sum = it1->val + it2->val + carry;
        if (sum >= 10)
            carry = 1;
        else
            carry = 0;

        int digit = sum % 10;
        head = addNode(head, digit);

        it1 = it1->next;
        it2 = it2->next;
    }
    if (carry == 1)
    {
        auto it = head;
        while(it->next != nullptr)
            it = it->next;
        it->next = new ListNode(1);
    }

    return head;
}

int main()
{
    auto n1 = new ListNode(2);
    auto n11 = new ListNode(4);
    auto n111 = new ListNode(3);

    auto n2 = new ListNode(5);
    auto n22 = new ListNode(6);
    auto n222 = new ListNode(4);

    n1->next = n11;
    n11->next = n111;

    n2->next = n22;
//    n22->next = n222;

    auto head = addTwoNumbers(n1, n2);
    while (head != nullptr)
    {
        cout << head->val << " - ";
        head = head->next;
    }
    cout << endl;
    return 0;
}
