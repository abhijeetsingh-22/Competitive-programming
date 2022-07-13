/*
 * @lc app=leetcode id=1614 lang=cpp
 *
 * [1614] Maximum Nesting Depth of the Parentheses
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxDepth(string s)
    {
        // stack<char> st;
        int n = s.size();
        int depth = 0, d = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                d++;
                // st.push('(');
            }
            else if (s[i] == ')')
            {
                d--;
                // st.pop();
            }
            depth = max(depth, d);
        }
        return depth;
    }
};
// @lc code=end
