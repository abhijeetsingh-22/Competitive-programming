/*
 * @lc app=leetcode id=1768 lang=cpp
 *
 * [1768] Merge Strings Alternately
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        int i = 0, j = 0;
        string ans;
        // while end of even one string is not reached add char by char alternatively
        while (word1[i] != '\0' and word2[j] != '\0')
        {
            if (i <= j)
            {
                ans.push_back(word1[i]);

                i++;
            }
            else
            {
                ans.push_back(word2[j]);

                j++;
            }
        }
        // add left over charactes from the string whichever is larger
        for (; i < word1.size(); i++)
        {
            ans.push_back(word1[i]);
        }
        for (; j < word2.size(); j++)
        {
            ans.push_back(word2[j]);
        }
        return ans;
    }
};
// @lc code=end
