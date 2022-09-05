/*
 * @lc app=leetcode id=429 lang=cpp
 *
 * [429] N-ary Tree Level Order Traversal
 */

 // @lc code=start
 /*
 // Definition for a Node.
 class Node {
 public:
     int val;
     vector<Node*> children;

     Node() {}

     Node(int _val) {
         val = _val;
     }

     Node(int _val, vector<Node*> _children) {
         val = _val;
         children = _children;
     }
 };
 */

class Solution {
    vector<vector<int>> bfs(Node* root) {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        //node,level
        queue <pair<Node*, int >>  q;
        q.push({ root,0 });
        q.push({ nullptr,-1 });

        while (!q.empty()) {
            Node* node = q.front().first;
            int level = q.front().second;
            q.pop();
            if (node) {
                if (ans.size() <= level)
                    ans.push_back({});
                ans[level].push_back(node->val);
                for (Node* n : node->children) {
                    q.push({ n,level + 1 });
                }

            }
            else {
                if (!q.empty())
                    q.push({ nullptr,-1 });
            }
        }
        return ans;
    }
public:
    vector<vector<int>> levelOrder(Node* root) {
        return bfs(root);
    }
};
// @lc code=end

