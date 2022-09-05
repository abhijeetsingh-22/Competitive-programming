/*
 * @lc app=leetcode id=987 lang=cpp
 *
 * [987] Vertical Order Traversal of a Binary Tree
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
class Solution {
    vector<vector<int>> level_order(TreeNode* root) {
        //d,level ,val
        map<int, map<int, multiset<int>>> ds;
        //node , d,level
        queue < pair<TreeNode*, pair<int, int>>>q;
        q.push({ root,{0,0} });
        while (!q.empty()) {
            auto cur = q.front();
            TreeNode* node = cur.first;
            int d = cur.second.first;
            int l = cur.second.second;
            q.pop();
            ds[d][l].insert(node->val);
            if (node->left)
                q.push({ node->left,{d - 1,l + 1} });
            if (node->right)
                q.push({ node->right,{d + 1,l + 1} });
        }
        vector<vector<int>> ans;
        for (auto& p : ds) {
            vector<int> col;
            for (auto& c : p.second) {
                col.insert(col.end(), c.second.begin(), c.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        return level_order(root);
    }
};
// @lc code=end

