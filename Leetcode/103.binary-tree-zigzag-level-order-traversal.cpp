/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
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
private:
    static int height(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int lh = height(root->left);
        int rh = height(root->right);
        return max(lh, rh) + 1;
    }
    static void print_klevel(TreeNode *root, int k, bool reverse, vector<int> &row)
    {
        if (root == NULL)
            return;
        if (k == 1)
        {
            row.push_back(root->val);
            return;
        }
        if (reverse)
        {
            print_klevel(root->right, k - 1, reverse, row);
            print_klevel(root->left, k - 1, reverse, row);
        }
        else
        {
            print_klevel(root->left, k - 1, reverse, row);
            print_klevel(root->right, k - 1, reverse, row);
        }
    }
    static void levelorder_zig_rec(TreeNode *root, vector<vector<int>> &ans)
    {
        if (root == NULL)
            return;
        int h = height(root);
        for (int i = 1; i <= h; i++)
        {
            vector<int> row;
            print_klevel(root, i, !(i & 1), row);
            ans.push_back(row);
        }
    }
    static void levelorder_zig(TreeNode *root, vector<vector<int>> &ans)
    {
        if (root == NULL)
            return;
        deque<TreeNode *> dq;
        dq.push_back(root);

        bool left_to_right = true;

        while (!dq.empty())
        {
            int sz = dq.size();
            vector<int> row(sz);
            for (int i = 0; i < sz; i++)
            {
                TreeNode *temp = left_to_right ? dq.front() : dq.back();
                row[i] = temp->val;
                if (left_to_right)
                {
                    if (temp->left)
                        dq.push_back(temp->left);
                    if (temp->right)
                        dq.push_back(temp->right);
                    dq.pop_front();
                }
                else
                {
                    if (temp->right)
                        dq.push_front(temp->right);
                    if (temp->left)
                        dq.push_front(temp->left);
                    dq.pop_back();
                }
            }
            ans.push_back(row);
            left_to_right = !left_to_right;
        }
    }

public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        levelorder_zig(root, ans);
        // levelorder_zig_rec(root, ans);
        return ans;
    }
};
// @lc code=end
