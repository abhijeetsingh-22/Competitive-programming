/*
 * @lc app=leetcode id=718 lang=cpp
 *
 * [718] Maximum Length of Repeated Subarray
 */

// @lc code=start
class Solution
{
    int find_len(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();

        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        int ans = 0;
        for (int idx1 = 1; idx1 <= n1; idx1++)
        {
            for (int idx2 = 1; idx2 <= n2; idx2++)
            {
                if (nums1[idx1 - 1] == nums2[idx2 - 1])
                {
                    dp[idx1][idx2] = 1 + dp[idx1 - 1][idx2 - 1];
                    ans = max(ans, dp[idx1][idx2]);
                }
                else
                    dp[idx1][idx2] = 0;
            }
        }
        return ans;
    }
    int find_len_sopt(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();

        vector<int> prev(n2 + 1, 0), cur(n2 + 1, 0);
        int ans = 0;
        for (int idx1 = 1; idx1 <= n1; idx1++)
        {
            for (int idx2 = 1; idx2 <= n2; idx2++)
            {
                if (nums1[idx1 - 1] == nums2[idx2 - 1])
                {
                    cur[idx2] = 1 + prev[idx2 - 1];
                    ans = max(ans, cur[idx2]);
                }
                else
                    cur[idx2] = 0;
            }
            prev = cur;
        }
        return ans;
    }

public:
    int findLength(vector<int> &nums1, vector<int> &nums2)
    {
        // return find_len(nums1, nums2);
        return find_len_sopt(nums1, nums2);
    }
};
// @lc code=end
