/*
 * @lc app=leetcode id=1457 lang=cpp
 *
 * [1457] Pseudo-Palindromic Paths in a Binary Tree
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
public:
    static int dfs(TreeNode *root, unordered_map<int, int> &elements, int depth)
    {
        if (root == nullptr)
            return 0;
        elements[root->val]++;
        if (root->left == nullptr and root->right == nullptr)
        {
            int odd_occ = 0;
            for (auto x : elements)
            {
                if (x.second & 1)
                    odd_occ++;
            }
            elements[root->val]--;
            if (depth & 1 and odd_occ == 1)
            {
                return 1;
            }
            else if (!(depth & 1) and odd_occ == 0)
            {
                return 1;
            }
            return 0;
        }
        int paths = dfs(root->left, elements, depth + 1) + dfs(root->right, elements, depth + 1);
        elements[root->val]--;
        return paths;
        // return 0;
    }

public:
    int pseudoPalindromicPaths(TreeNode *root)
    {
        unordered_map<int, int> elements;
        return dfs(root, elements, 1);
    }
};
// @lc code=end
