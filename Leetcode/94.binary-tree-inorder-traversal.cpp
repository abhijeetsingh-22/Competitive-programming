/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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
class Solution
{
    /*
    This is TC->O(n) and SC->O(n)
    */
private:
    static void inorder_rec(TreeNode *root, vector<int> &ans)
    {
        if (root == NULL)
            return;
        inorder_rec(root->left, ans);
        ans.push_back(root->val);
        inorder_rec(root->right, ans);
    }

    // Using morris traversal which uses O(1) space;
    static void inorder_morris(TreeNode *root, vector<int> &ans)
    {
        if (root == NULL)
            return;
        TreeNode *cur = root;
        while (cur != NULL)
        {
            if (cur->left)
            {
                TreeNode *prev = cur->left;
                while (prev->right != NULL and prev->right != cur)
                {
                    prev = prev->right;
                }
                // left subtree of cur node has not been visited
                if (prev->right == NULL)
                {
                    prev->right = cur;
                    cur = cur->left;
                }
                // left subtree have been visited and cur have come 2nd time
                if (prev->right == cur)
                {
                    prev->right = NULL;
                    ans.push_back(cur->val);
                    cur = cur->right;
                }
            }
            else
            // cur have no left subtree or left subtree is null
            {
                ans.push_back(cur->val);
                cur = cur->right;
            }
        }
    }
    static void inorder_iter(TreeNode *root, vector<int> &ans)
    {
        if (root == NULL)
            return;
        stack<TreeNode *> stk;
        TreeNode *ptr = root->left;
        stk.push(root);
        while (!stk.empty() or ptr != NULL)
        {

            if (ptr)
            {
                stk.push(ptr);
                ptr = ptr->left;
            }
            else
            {
                auto top = stk.top();
                ptr = top->right;

                ans.push_back(top->val);
                stk.pop();
            }
        }
    }

public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        // inorder_morris(root, ans);
        inorder_iter(root, ans);
        return ans;
    }
};
// @lc code=end
