/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    static bool isAlphaNum(char c)
    {
        int ascii = (int)c;
        return ((ascii >= 97 && ascii <= 122) || (ascii >= 65 && ascii <= 90) || (ascii >= 48 && ascii <= 57));
    }

public:
    bool isPalindrome(string s)
    {
        int i = 0, j = 0;
        while (s[j] != '\0')
        {
            if (isAlphaNum(s[j]))
            {
                s[i] = tolower(s[j]);
                i++;
                j++;
            }
            else
                j++;
        }
        j = i - 1;
        i = 0;
        while (i <= j)
        {
            if (s[i] == s[j])
            {
                j--;
                i++;
            }
            else
                return false;
        }
        return true;
    }
};
// @lc code=end
