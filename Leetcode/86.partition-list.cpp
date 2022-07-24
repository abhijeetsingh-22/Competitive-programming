/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
 */

// @lc code=start
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
class Solution
{
private:
    static void swap_nodes(ListNode *&p, ListNode *&prevP, ListNode *&q, ListNode *&prevQ, ListNode *&head)
    {
        // swapping p  and q
        if (prevP == nullptr)
        {
            head = q;
        }
        else
            prevP->next = q;
        if (prevQ)
            prevQ->next = p;

        // swapping next pointers
        ListNode *temp = p->next;
        p->next = q->next;
        q->next = temp;
    }

public:
    ListNode *partition(ListNode *head, int x)
    {
        if (head == nullptr or head->next == nullptr)
            return head;

        ListNode *p = head, *prev = nullptr;
        while (p != nullptr and p->val < x)
        {
            prev = p;
            p = p->next;
        }
        if (p == nullptr)
        {
            return head;
        }
        ListNode *q = p->next, *prevQ = p;

        while (q != nullptr)
        {
            if (q->val < x)
            {
                // remove q from its place
                prevQ->next = q->next;
                ListNode *temp = q->next;
                if (prev != nullptr)
                {
                    q->next = prev->next;
                    prev->next = q;
                }
                else
                {
                    q->next = head;
                    head = q;
                }
                prev = q;
                q = temp;
            }
            else
            {
                prevQ = q;
                q = q->next;
            }
        }

        return head;
    }
};
// @lc code=end
