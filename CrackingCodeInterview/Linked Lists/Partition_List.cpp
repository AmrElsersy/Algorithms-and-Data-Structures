/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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

ListNode* partition2(ListNode* head, int x) {
    if (!head)
        return nullptr;
    else if (head->next == nullptr)
        return head;

    ListNode *lessList = nullptr;
    ListNode *greaterList = nullptr;

    auto it = head;
    while (it != nullptr)
    {
        if (it->val < x)
            lessList = addNode(lessList, it->val);
        else
            greaterList = addNode(greaterList, it->val);

        it = it->next;
    }

    it = lessList;
    if (!lessList)
        return greaterList;

    while (it->next != nullptr)
        it = it->next;

    it->next = greaterList;
    return lessList;
}

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        return partition2(head, x);
    }
};
