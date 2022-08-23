/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
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
    ListNode *find_mid(ListNode *head)
    {
        ListNode *fast = head, *slow = head, *prev;
        while (fast and fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev = nullptr;
        return slow;
    }
    ListNode *reverse_ll(ListNode *head)
    {
        ListNode *prev = nullptr, *cur = head, *temp;
        while (cur)
        {
            temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        return prev;
    }

public:
    bool isPalindrome(ListNode *head)
    {
        ListNode *mid = find_mid(head);
        ListNode *head2 = reverse_ll(mid);
        mid->next = nullptr;

        while (head and head2)
        {
            if (head->val != head2->val)
                return false;
            head = head->next;
            head2 = head2->next;
        }
        return true;
    }
};
// @lc code=end
