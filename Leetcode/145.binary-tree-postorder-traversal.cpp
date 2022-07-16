/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    // solving this using all 3 methods;
private:
    static void post_order_rec(TreeNode *root, vector<int> &ans)
    {
        if (root == NULL)
            return;
        post_order_rec(root->left, ans);
        post_order_rec(root->right, ans);
        ans.push_back(root->val);
    }
    static void post_order_iter(TreeNode *root, vector<int> &ans)
    {
        if (root == NULL)
            return;
        stack<TreeNode *> stk;
        stk.push(root);
        TreeNode *cur = root->left;
        while (!stk.empty() or cur != NULL)
        {
            if (cur)
            { // if cur node have left subtree push it into the stack
                stk.push(cur);
                cur = cur->left;
            }
            else
            { // check if there is any right subtree to the parent of cur as cur is null
                TreeNode *temp = stk.top()->right;
                // if right subtree is not present pop the cur node and go back till we get a node
                //  in the stk that have unvisited right subtree
                if (temp == NULL)
                {
                    ans.push_back(stk.top()->val);
                    temp = stk.top();
                    stk.pop();
                    while (!stk.empty() and temp == stk.top()->right)
                    {
                        temp = stk.top();
                        ans.push_back(temp->val);
                        stk.pop();
                    }
                }
                else
                {

                    cur = temp;
                }
            }
        }
    }

public:
    vector<int>
    postorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        // post_order_rec(root, ans);
        post_order_iter(root, ans);
        return ans;
    }
};
// @lc code=end
