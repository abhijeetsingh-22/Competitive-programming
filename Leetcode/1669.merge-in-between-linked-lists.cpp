/*
 * @lc app=leetcode id=1669 lang=cpp
 *
 * [1669] Merge In Between Linked Lists
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
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
    {

        ListNode *temp = list1, *s;
        int jump = 0;
        while (jump < a - 1)
        {
            temp = temp->next;
            jump++;
        }
        s = temp;
        while (jump <= b)
        {
            temp = temp->next;
            jump++;
        }
        s->next = list2;

        while (list2->next != NULL)
            list2 = list2->next;
        list2->next = temp;
        return list1;
    }
};
// @lc code=end
