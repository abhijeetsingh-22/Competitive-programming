/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
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
    TreeNode *array_to_bst(int start, int end, vector<int> &nums)
    {
        if (start > end)
            return nullptr;
        if (start == end)
            return new TreeNode(nums[start]);

        int mid = (start + end) / 2;
        TreeNode *node = new TreeNode(nums[mid]);
        node->left = array_to_bst(start, mid - 1, nums);
        node->right = array_to_bst(mid + 1, end, nums);

        return node;
    }

public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {

        int n = nums.size();
        return array_to_bst(0, n - 1, nums);
    }
};
// @lc code=end
