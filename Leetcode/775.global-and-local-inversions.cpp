/*
 * @lc app=leetcode id=775 lang=cpp
 *
 * [775] Global and Local Inversions
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    // Divide and counquer solution TC-> O(nlogn)
    // private:
    //     static long long merge(vector<int> &nums, long long start, long long end)
    //     {
    //         long long mid = (start + end) / 2;
    //         long long i = start, j = mid + 1, k = start, count = 0;
    //         long long temp[100000];
    //         while (i <= mid && j <= end)
    //         {
    //             if (nums[i] < nums[j])
    //             {
    //                 temp[k++] = nums[i++];
    //             }
    //             else
    //             {
    //                 temp[k++] = nums[j++];
    //                 count += (mid - i + 1);
    //             }
    //         }
    //         while (i <= mid)
    //         {
    //             temp[k++] = nums[i++];
    //         }
    //         while (j <= end)
    //         {
    //             temp[k++] = nums[j++];
    //         }
    //         for (long long idx = start; idx <= end; idx++)
    //         {
    //             nums[idx] = temp[idx];
    //         }
    //         return count;
    //     }
    //     static long long count_global_inversion(vector<int> &nums, long long start, long long end)
    //     {
    //         if (start >= end)
    //             return 0;
    //         long long mid = (start + end) / 2;
    //         long long x = count_global_inversion(nums, start, mid);
    //         long long y = count_global_inversion(nums, mid + 1, end);
    //         long long z = merge(nums, start, end);
    //         return (x + y + z);
    //     }

    // public:
    //     bool isIdealPermutation(vector<int> &nums)
    //     {
    //         long long l_inv = 0, g_inv;
    //         long long n = nums.size();
    //         for (long long i = 0; i < n - 1; i++)
    //         {
    //             if (nums[i] > nums[i + 1])
    //                 l_inv++;
    //         }
    //         g_inv = count_global_inversion(nums, 0, n - 1);
    //         return g_inv == l_inv;
    //     }

    // O(n) solution
public:
    bool isIdealPermutation(vector<int> &nums)
    {
        int n = nums.size(), cmax = 0;
        for (int i = 0; i < n - 2; i++)
        {
            cmax = max(cmax, nums[i]);
            if (cmax > nums[i + 2])
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
