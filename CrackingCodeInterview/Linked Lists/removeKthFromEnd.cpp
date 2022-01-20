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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (!head)
        return head;

    int sizeList = 0;
    auto it = head;
    while (it != nullptr)
    {
        sizeList++;
        it = it->next;
    }

    int k = sizeList - n;

    int i =0;
    it = head;
    auto prev = it;
    while (i < k)
    {
        prev = it;
        it = it->next;
        i++;
    }

    prev->next = it->next;
    if (it == head)
    {
        head = head->next;
        delete it;
        return head;
    }
    else
    {
        delete it;
        return head;
    }

    }
};
