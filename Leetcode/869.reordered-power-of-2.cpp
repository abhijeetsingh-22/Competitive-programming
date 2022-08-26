/*
 * @lc app=leetcode id=869 lang=cpp
 *
 * [869] Reordered Power of 2
 */

// @lc code=start
class Solution
{
    bool can_reorder(int cur, int rem_len, vector<int> freq)
    {
        if (rem_len == 0)
        {
            return (cur & (cur - 1)) == 0;
        }
        for (int i = 0; i <= 9; i++)
        {
            if (cur == 0 and i == 0)
                continue;
            if (freq[i])
            {
                freq[i]--;
                if (can_reorder(cur * 10 + i, rem_len - 1, freq))
                    return true;
                freq[i]++;
            }
        }
        return false;
    }
    vector<int> get_freq(int n)
    {
        int num = n, len = 0;
        vector<int> freq(10, 0);
        while (num)
        {
            len++;
            int rem = num % 10;
            freq[rem]++;
            num = num / 10;
        }
        return freq;
    }

    bool can_reorder_opt(int n)
    {
        vector<int> freq_in_n = get_freq(n);

        for (int i = 0; i <= 29; i++)
        {
            if (freq_in_n == get_freq(1 << i))
                return true;
        }
        return false;
    }

public:
    bool reorderedPowerOf2(int n)
    {
        // vector<int> freq = get_freq(n);

        // return can_reorder(0, len, freq);
        return can_reorder_opt(n);
    }
};
// @lc code=end
