/*
 * @lc app=leetcode id=328 lang=cpp
 *
 * [328] Odd Even Linked List
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
public:
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == NULL or head->next == NULL)
            return head;
        ListNode *odd_head = head;
        ListNode *even_head = head->next;
        ListNode *odd_ptr = odd_head;
        ListNode *even_ptr = even_head;
        while (even_ptr != NULL and odd_ptr != NULL)
        {
            if (even_ptr->next)
            {
                odd_ptr->next = even_ptr->next;
                odd_ptr = odd_ptr->next;
            }
            else
                break;
            if (odd_ptr->next)
            {
                even_ptr->next = odd_ptr->next;
                even_ptr = even_ptr->next;
            }
            else
                break;
        }
        odd_ptr->next = even_head;
        even_ptr->next = NULL;
        return head;
    }
};
// @lc code=end
