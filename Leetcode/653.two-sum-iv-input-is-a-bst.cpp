/*
 * @lc app=leetcode id=653 lang=cpp
 *
 * [653] Two Sum IV - Input is a BST
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
class BST_iterator
{
private:
    stack<TreeNode *> stk;
    bool forward;

public:
    BST_iterator(TreeNode *root, bool forward)
    {
        this->forward = forward;
        TreeNode *cur = root;
        while (cur != NULL)
        {
            if (cur)
            {
                stk.push(cur);
                cur = forward ? cur->left : cur->right;
            }
        }
    }
    bool has_next()
    {
        return !stk.empty();
    }
    int next()
    {
        int next_value = stk.top()->val;
        TreeNode *cur = stk.top();
        stk.pop();
        cur = forward ? cur->right : cur->left;
        while (cur)
        {
            stk.push(cur);
            cur = forward ? cur->left : cur->right;
        }

        return next_value;
    }
};
class Solution
{
private:
    // TC->O(n) SC->O(n*h);
    static bool dfs(TreeNode *root, unordered_set<int> &s, int k)
    {
        if (root == NULL)
            return false;
        if (s.count(k - root->val))
            return true;
        s.insert(root->val);
        return dfs(root->left, s, k) or dfs(root->right, s, k);
    }
    static bool find_using_bfs_iterator(TreeNode *root, int k)
    {
        BST_iterator l_iter(root, true), r_iter(root, false);
        int left = l_iter.next(), right = r_iter.next();
        while (left < right)
        {
            int sum = left + right;
            if (sum == k)
                return true;
            if (sum < k)
                left = l_iter.next();
            else
                right = r_iter.next();
        }
        return false;
    }

public:
    bool findTarget(TreeNode *root, int k)
    {
        // unordered_set<int> s;
        // return dfs(root, s, k);
        return find_using_bfs_iterator(root, k);
    }
};
// @lc code=end
