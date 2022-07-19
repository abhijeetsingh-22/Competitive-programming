/*
 * @lc app=leetcode id=1305 lang=cpp
 *
 * [1305] All Elements in Two Binary Search Trees
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
    static void dfs(TreeNode *root, vector<int> &v)
    {
        if (root == NULL)
            return;
        dfs(root->left, v);
        v.push_back(root->val);
        dfs(root->right, v);
    }
    static void merge(vector<int> &v1, vector<int> &v2, vector<int> &ans)
    {
        int idx1 = 0, idx2 = 0;
        int s1 = v1.size();
        int s2 = v2.size();
        while (idx1 < s1 and idx2 < s2)
        {
            if (v1[idx1] < v2[idx2])
            {
                ans.push_back(v1[idx1++]);
            }
            else
                ans.push_back(v2[idx2++]);
        }
        while (idx1 < s1)
            ans.push_back(v1[idx1++]);
        while (idx2 < s2)
            ans.push_back(v2[idx2++]);
    }
    static vector<int> dfs_iter(TreeNode *root1, TreeNode *root2)
    {

        stack<TreeNode *> stk1, stk2;
        TreeNode *ptr1 = root1, *ptr2 = root2;
        vector<int> ans;

        while (ptr1)
        {
            stk1.push(ptr1);
            ptr1 = ptr1->left;
        }
        while (ptr2)
        {
            stk2.push(ptr2);
            ptr2 = ptr2->left;
        }
        while (!stk1.empty() and !stk2.empty())
        {
            ptr1 = stk1.top();
            ptr2 = stk2.top();
            if (ptr1->val < ptr2->val)
            {
                stk1.pop();
                ans.push_back(ptr1->val);

                ptr1 = ptr1->right;
                while (ptr1)
                {
                    stk1.push(ptr1);
                    ptr1 = ptr1->left;
                };
            }
            else
            {
                stk2.pop();
                ans.push_back(ptr2->val);
                ptr2 = ptr2->right;
                // stk2.push(ptr2);
                while (ptr2)
                {
                    stk2.push(ptr2);
                    ptr2 = ptr2->left;
                };
            }
        }
        while (!stk1.empty())
        {
            ptr1 = stk1.top();

            stk1.pop();
            ans.push_back(ptr1->val);
            ptr1 = ptr1->right;
            while (ptr1)
            {
                stk1.push(ptr1);
                ptr1 = ptr1->left;
            }
        }
        while (!stk2.empty())
        {
            ptr2 = stk2.top();

            stk2.pop();
            ans.push_back(ptr2->val);
            ptr2 = ptr2->right;
            while (ptr2)
            {
                stk2.push(ptr2);
                ptr2 = ptr2->left;
            }
        }
        return ans;
    }

public:
    vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
    {
        // vector<int> v1, v2, ans;
        // dfs(root1, v1);
        // dfs(root2, v2);
        // merge(v1, v2, ans);
        // return ans;
        return dfs_iter(root1, root2);
    }
};
// @lc code=end
