/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
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
    // return  kth,count
    int kth_smallest(TreeNode *root, int &k)
    {
        if (root == NULL)
        {
            return -1;
        }
        int l = kth_smallest(root->left, k);
        k--;
        if (k == 0)
        {
            return root->val;
        }
        int r = kth_smallest(root->right, k);
        return max(l, r);
    }
    static int kth_smallest_inorder_morris(TreeNode *root, int k)
    {
        TreeNode *cur = root;
        int count = 0;
        int ans;

        while (cur != NULL)
        {
            if (cur->left)
            {
                TreeNode *prev = cur->left;
                while (prev->right != NULL and prev->right != cur)
                {
                    prev = prev->right;
                }

                if (prev->right == NULL)
                {
                    prev->right = cur;
                    cur = cur->left;
                }
                if (prev->right == cur)
                {
                    prev->right = NULL;
                    count++;
                    if (count == k)
                        ans = cur->val;

                    cur = cur->right;
                }
            }
            else
            {
                count++;

                if (count == k)
                    ans = cur->val;
                cur = cur->right;
            }
        }
        return ans;
    }

public:
    int kthSmallest(TreeNode *root, int k)
    {
        return kth_smallest(root, k);
        // return kth_smallest_inorder_morris(root, k);
    }
};
// @lc code=end
