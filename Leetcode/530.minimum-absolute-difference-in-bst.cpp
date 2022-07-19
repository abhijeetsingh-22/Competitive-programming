/*
 * @lc app=leetcode id=530 lang=cpp
 *
 * [530] Minimum Absolute Difference in BST
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
class min_max
{
public:
    int min_val;
    int max_val;
    int min_dif;
    min_max()
    {
        min_val = INT_MAX;
        max_val = INT_MIN;
        min_dif = INT_MAX;
    }
};
class Solution
{
private:
    int minimum = INT_MAX;
    // TC-> O(n) SC->O(h) log(n)<=h<=n;
    static min_max get_min_dif(TreeNode *root)
    {
        min_max ans;
        if (root == NULL)
        {
            return ans;
        }
        if (root->right == NULL and root->left == NULL)
        {
            ans.max_val = root->val;
            ans.min_val = root->val;
            return ans;
        }
        min_max left = get_min_dif(root->left);
        min_max right = get_min_dif(root->right);

        int min_cur;
        if (root->left == NULL)
        {

            min_cur = abs(root->val - right.min_val);
            ans.min_dif = min(min_cur, right.min_dif);
        }
        else if (root->right == NULL)
        {
            min_cur = abs(root->val - left.max_val);
            ans.min_dif = min(min_cur, left.min_dif);
        }
        else
        {
            min_cur = min(abs(root->val - left.max_val), abs(root->val - right.min_val));
            ans.min_dif = min(min_cur, min(left.min_dif, right.min_dif));
        }
        ans.min_val = min(min(left.min_val, right.min_val), root->val);
        ans.max_val = max(max(left.max_val, right.max_val), root->val);

        return ans;
    }
    void inorder_rec(TreeNode *root, int &prev)
    {
        if (root == NULL)
            return;
        inorder_rec(root->left, prev);
        if (prev >= 0)
            minimum = min(minimum, abs(root->val - prev));
        prev = root->val;
        inorder_rec(root->right, prev);
    }
    int inorder_morris(TreeNode *root)
    {
        int min_dif = INT_MAX;
        int prev = -1;

        TreeNode *cur = root;
        while (cur != NULL)
        {

            if (cur->left)
            {
                TreeNode *next = cur->left;
                while (next->right != NULL and next->right != cur)
                    next = next->right;

                if (next->right == NULL)
                {
                    next->right = cur;
                    cur = cur->left;
                }
                if (next->right == cur)
                {
                    next->right = NULL;
                    if (prev > -1)
                    {
                        min_dif = min(min_dif, abs(cur->val - prev));
                    }
                    prev = cur->val;
                    cur = cur->right;
                }
            }
            else
            {
                if (prev > -1)
                {

                    min_dif = min(min_dif, abs(cur->val - prev));
                }
                prev = cur->val;
                cur = cur->right;
            }
        }
        return min_dif;
    }

public:
    int getMinimumDifference(TreeNode *root)
    {
        return inorder_morris(root);
        // int prev = -1;
        // inorder_rec(root, prev);
        // return minimum;
        // return get_min_dif(root).min_dif;
    }
};
// @lc code=end
