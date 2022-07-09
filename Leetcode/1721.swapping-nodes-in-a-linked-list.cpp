/*
 * @lc app=leetcode id=1721 lang=cpp
 *
 * [1721] Swapping Nodes in a Linked List
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
    ListNode *swapNodes(ListNode *head, int k)
    {

        ListNode *temp;
        ListNode *prevX = NULL, *curX = head;
        ListNode *prevY = NULL, *curY = head;
        int idx = 1;
        while (idx <= k - 1)
        {
            prevX = curX;
            curX = curX->next;
            idx++;
        }
        temp = curX;
        while (temp->next != NULL)
        {
            prevY = curY;
            curY = curY->next;
            temp = temp->next;
        }
        if (prevX != NULL)
        {
            prevX->next = curY;
        }
        else
            head = curY;

        if (prevY != NULL)
            prevY->next = curX;
        else
            head = curX;
        temp = curX->next;
        curX->next = curY->next;
        curY->next = temp;

        return head;
    }
};
// @lc code=end
