/*
 * @lc app=leetcode id=226 lang=cpp
 *
 * [226] Invert Binary Tree
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
    static void invert_rec(TreeNode *root)
    {
        if (root == NULL)
            return;

        invert_rec(root->left);
        invert_rec(root->right);

        TreeNode *temp;
        temp = root->left;

        root->left = root->right;
        root->right = temp;
    }
    static void invert_iter(TreeNode *root)
    {
        if (root == NULL)
            return;
        stack<TreeNode *> stk;

        // stk.push(root);
        TreeNode *cur = root;
        while (!stk.empty() or cur != NULL)
        {
            if (cur)
            {
                stk.push(cur);
                cur = cur->left;
            }
            else
            {
                TreeNode *temp = stk.top()->right;
                if (temp == NULL)
                {
                    // swap the links
                    TreeNode *helper;
                    temp = stk.top();

                    helper = temp->left;
                    temp->left = temp->right;
                    temp->right = helper;
                    stk.pop();

                    while (!stk.empty() and stk.top()->right == temp)
                    {

                        temp = stk.top();
                        helper = temp->left;
                        temp->left = temp->right;
                        temp->right = helper;
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
    // queue BFS will be very similar to this just take front pop it
    // swap left and right and push
    // its childern into the back
    static void invert_iter2(TreeNode *root)
    {
        if (root == NULL)
            return;

        stack<TreeNode *> stk;
        stk.push(root);
        while (!stk.empty())
        {
            TreeNode *temp, *cur = stk.top();
            stk.pop();
            if (cur->right)
                stk.push(cur->right);
            if (cur->left)
                stk.push(cur->left);

            // swapping left and right nodes;
            temp = cur->left;
            cur->left = cur->right;
            cur->right = temp;
        }
    }

public:
    TreeNode *invertTree(TreeNode *root)
    {
        // invert_rec(root);
        // invert_iter(root);
        invert_iter2(root);
        return root;
    }
};
// @lc code=end
