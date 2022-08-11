/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
    bool is_valid_bst(TreeNode *root, long long lb, long long ub)
    {
        if (root == nullptr)
            return true;

        if (root->val <= lb or root->val >= ub)
            return false;

        return is_valid_bst(root->left, lb, root->val) and is_valid_bst(root->right, root->val, ub);
    }
    bool is_valid_bst_morris(TreeNode *root)
    {
        if (root == nullptr)
            return true;
        TreeNode *cur = root;
        long long last_number = INT_MIN;
        last_number--;
        bool ans = true;
        while (cur != nullptr)
        {
            if (cur->left)
            {
                TreeNode *prev = cur->left;
                while (prev->right != nullptr and prev->right != cur)
                {
                    prev = prev->right;
                }
                if (prev->right == nullptr)
                {
                    prev->right = cur;
                    cur = cur->left;
                }
                if (prev->right == cur)
                {
                    prev->right = nullptr;
                    if (cur->val <= last_number)
                        ans = false;
                    // last_number = 5;
                    last_number = (long long)cur->val;
                    cur = cur->right;
                }
            }
            else
            {

                if (cur->val <= last_number)
                    ans = false;
                last_number = cur->val;
                cur = cur->right;
            }
        }
        return ans;
    }

public:
    bool isValidBST(TreeNode *root)
    {
        // long long lb = INT_MIN;
        // lb--;
        // long long ub = INT_MAX;
        // ub++;
        // return is_valid_bst(root, lb, ub);
        return is_valid_bst_morris(root);
    }
};
// @lc code=end
