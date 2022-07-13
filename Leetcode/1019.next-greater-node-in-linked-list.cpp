/*
 * @lc app=leetcode id=1019 lang=cpp
 *
 * [1019] Next Greater Node In Linked List
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
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // TC-> O(n^2) and SC->O(1)
    // vector<int> nextLargerNodes(ListNode *head)
    // {
    //     vector<int> ans;
    //     ListNode *cur = head;
    //     int i = 0;
    //     while (cur != NULL)
    //     {
    //         ListNode *fwd;
    //         fwd = cur->next;
    //         while (fwd != NULL and fwd->val <= cur->val)
    //             fwd = fwd->next;
    //         int val = fwd ? fwd->val : 0;
    //         ans.push_back(val);
    //         cur = cur->next;
    //     }
    //     return ans;
    // }

    // TC->O(N) SC-> O(N)
    vector<int> nextLargerNodes(ListNode *head)
    {
        // stack of (idx,val)
        stack<pair<int, int>> st;
        vector<int> ans;
        int cur_idx = 0;
        while (head != nullptr)
        {
            ans.push_back(0);
            while (!st.empty() and head->val > st.top().second)
            {
                int idx = st.top().first;
                ans[idx] = head->val;
                st.pop();
            }
            st.push(make_pair(cur_idx, head->val));
            cur_idx++;
            head = head->next;
        }
        return ans;
    }
};
// @lc code=end
