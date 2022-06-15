/*
 * @lc app=leetcode id=443 lang=cpp
 *
 * [443] String Compression
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    static int addCount(vector<char> &chars, int count, int idx)
    {
        if (count <= 1)
            return idx + count;
        idx++;
        vector<char> num;

        while (count > 0)
        {
            num.push_back((char)(count % 10) + 48);
            count /= 10;
        }
        reverse(num.begin(), num.end());
        for (auto &x : num)
        {
            chars[idx] = x;
            idx++;
        }
        return idx;
    }

public:
    int compress(vector<char> &chars)
    {
        int i = 0, j = 0, n = chars.size(), count = 0;
        int p, d;
        if (n == 1)
            return 1;
        while (j < n)
        {

            if (chars[i] == chars[j])
            {
                count++;
                j++;
            }
            else
            {

                i = addCount(chars, count, i);

                count = 0;
                chars[i] = chars[j];
            }
        }

        i = addCount(chars, count, i);

        return i;
    }
};
// @lc code=end
