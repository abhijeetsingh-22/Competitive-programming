/*
 * @lc app=leetcode id=921 lang=cpp
 *
 * [921] Minimum Add to Make Parentheses Valid
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Using stack so TC-> O(n) and SC-> O(n);
    // int minAddToMakeValid(string s)
    // {
    //     stack<char> st;
    //     int steps = 0;
    //     for (auto ch : s)
    //     {
    //         if (ch == '(')
    //             st.push(ch);
    //         else if (ch == ')')
    //         {
    //             if (!st.empty())
    //                 st.pop();
    //             else
    //                 steps++;
    //         }
    //     }
    //     while (!st.empty())
    //     {
    //         steps++;
    //         st.pop();
    //     }
    //     return steps;
    // }

    // Now without using stack so SC-> O(1) and TC-> O(n);
    int minAddToMakeValid(string s)
    { // number of left and right brackets required
        int left = 0, right = 0;
        for (char ch : s)
        {
            if (ch == '(')
            {
                right++;
            }
            else if (ch == ')')
            {
                if (right > 0)
                    right--;
                else
                    left++;
            }
        }
        return right + left;
    }
};
// @lc code=end
