/*
 * @lc app=leetcode id=2160 lang=cpp
 *
 * [2160] Minimum Sum of Four Digit Number After Splitting Digits
 */

// @lc code=start
class Solution
{
private:
    static int min_sum(int num)
    {
        int freq[10] = {0};
        while (num)
        {
            int rem = num % 10;
            freq[rem]++;
            num = num / 10;
        }
        int new1 = 0, new2 = 0;
        for (int i = 0; i < 10; i++)
        {
            while (freq[i])
            {
                if (new2 > new1)
                {
                    new1 *= 10;
                    new1 += i;
                }
                else
                {
                    new2 *= 10;
                    new2 += i;
                }
                freq[i]--;
            }
        }
        return new1 + new2;
    }

public:
    int minimumSum(int num)
    {
        return min_sum(num);
    }
};
// @lc code=end
