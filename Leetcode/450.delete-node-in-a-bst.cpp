/*
 * @lc app=leetcode id=450 lang=cpp
 *
 * [450] Delete Node in a BST
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
    static TreeNode *dfs_delete(TreeNode *root, int key)
    {
        if (root == NULL)
            return NULL;
        if (root->val == key)
        {
            // case 3
            if (root->left != NULL and root->right != NULL)
            {
                TreeNode *temp = root->right;
                while (temp->left != NULL)
                    temp = temp->left;

                root->val = temp->val;
                root->right = dfs_delete(root->right, temp->val);
                return root;
            }
            // case 1 leaf node
            if (root->left == NULL and root->right == NULL)
            {
                delete root;
                return NULL;
            }

            // case 2 node with 1 child
            if (root->left or root->right)
            {
                TreeNode *temp;
                if (root->left)
                {
                    temp = root->left;
                    delete root;
                    return temp;
                }
                if (root->right)
                {
                    temp = root->right;
                    delete root;
                    return temp;
                }
                        }
        }
        else if (root->val < key)
        {
            root->right = dfs_delete(root->right, key);
        }
        root->left = dfs_delete(root->left, key);
        return root;
    }

public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        return dfs_delete(root, key);
    }
};
// @lc code=end
