/*
 * @lc app=leetcode id=1111 lang=cpp
 *
 * [1111] Maximum Nesting Depth of Two Valid Parentheses Strings
 */

// @lc code=start
class Solution
{
public:
    vector<int> maxDepthAfterSplit(string seq)
    {

        int d = 0, depth = 0;
        int l1 = 0, l2 = 0, i = 0;
        vector<int> ans(seq.size(), 1);
        for (char ch : seq)
        {
            if (ch == '(')
            {
                d++;
                if (l1 <= l2)
                {
                    ans[i] = 0;
                    l1++;
                }
                else
                    l2++;
            }
            else if (ch == ')')
                if (l1 >= l2)
                {
                    ans[i] = 0;
                    l1--;
                }
                else
                    l2--;
            i++;
        }

        return ans;
    }
};
// @lc code=end
