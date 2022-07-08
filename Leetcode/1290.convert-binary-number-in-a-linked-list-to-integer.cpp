/*
 * @lc app=leetcode id=1290 lang=cpp
 *
 * [1290] Convert Binary Number in a Linked List to Integer
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

    // private:
    //     static int length(ListNode *head)
    //     {
    //         int l = 0;
    //         while (head != NULL)
    //         {
    //             l++;
    //             head = head->next;
    //         }
    //         return l;
    //     }

public:
    // 2 PASS approach
    // int getDecimalValue(ListNode *head)
    // {
    //     int i = 0, ans = 0;
    //     int len = length(head);
    //     while (head != NULL)
    //     {
    //         if (head->val == 1)
    //             ans = ans | (1 << len - i - 1);
    //         i++;
    //         head = head->next;
    //     }
    //     return ans;
    // }
    int getDecimalValue(ListNode *head)
    {
        int ans = 0;
        while (head != NULL)
        {
            ans = ans << 1;
            ans = ans | head->val;
            head = head->next;
        }
        return ans;
    }
};
// @lc code=end
