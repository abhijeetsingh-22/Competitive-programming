/*
 * @lc app=leetcode id=2130 lang=cpp
 *
 * [2130] Maximum Twin Sum of a Linked List
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
    static void reverse_ll(ListNode *&head)
    {
        if (head == NULL)
            return;
        ListNode *prev = NULL, *cur = head, *next = head;
        while (cur != NULL)
        {
            next = next->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        head = prev;
    }

public:
    int pairSum(ListNode *head)
    {
        ListNode *slow = head, *fast = head;
        while (fast != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        int cur, m = 0;
        reverse_ll(slow);
        while (slow != NULL)
        {
            cur = slow->val + head->val;
            m = max(m, cur);
            slow = slow->next;
            head = head->next;
        }
        return m;
    }
};
// @lc code=end
