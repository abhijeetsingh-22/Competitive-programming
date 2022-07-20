/*
 * @lc app=leetcode id=129 lang=cpp
 *
 * [129] Sum Root to Leaf Numbers
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptrptr), right(nullptrptr) {}
 *     TreeNode(int x) : val(x), left(nullptrptr), right(nullptrptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
private:
    static void dfs(TreeNode *root, int num, int &ans)
    {
        if (root == nullptr)
            return;
        num += (root->val);
        if (!root->left and !root->right)
        {
            ans += num;
            return;
        }

        dfs(root->left, num * 10, ans);
        dfs(root->right, num * 10, ans);
    }
    static int dfs_morris(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int ans = 0;
        int num = 0;
        int depth = 0;
        TreeNode *cur = root;
        while (cur)
        {
            depth = 1;
            if (cur->left)
            {
                TreeNode *prev = cur->left;
                while (prev->right != nullptr and prev->right != cur)
                {
                    prev = prev->right;
                    depth++;
                }
                // cur node is visited for first time
                if (prev->right == nullptr)
                {
                    prev->right = cur;
                    num = (num * 10) + cur->val;
                    cur = cur->left;
                }
                // cur node is visited second time
                if (prev->right == cur)
                {
                    // check if prev is leaf node then add number to ans
                    if (prev->left == nullptr)
                    {
                        ans += num;
                    }
                    prev->right = nullptr;
                    num = num / pow(10, depth);
                    cur = cur->right;
                }
            }
            else
            {
                num = num * 10 + cur->val;
                if (cur->right == nullptr)
                    ans += num;
                cur = cur->right;
            }
        }
        return ans;
    }

public:
    int sumNumbers(TreeNode *root)
    {
        // int ans = 0;
        // dfs(root, 0, ans);
        // return ans;
        return dfs_morris(root);
    }
};
// @lc code=end
