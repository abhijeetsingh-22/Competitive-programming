/*
 * @lc app=leetcode id=845 lang=cpp
 *
 * [845] Longest Mountain in Array
 */

// @lc code=start
class Solution
{
public:
    int longestMountain(vector<int> &arr)
    {

        // // TC-> O(n) SC-> O(n)
        // int n = arr.size();
        // int inc[n], dec[n], ans;
        // inc[0] = 1;
        // dec[n - 1] = 1;
        // for (int i = 1; i < n; i++)
        // {
        //     if (arr[i - 1] < arr[i])
        //         inc[i] = inc[i - 1] + 1;
        //     else
        //         inc[i] = 1;
        // }
        // for (int i = n - 2; i >= 0; i--)
        // {
        //     if (arr[i + 1] < arr[i])
        //         dec[i] = dec[i + 1] + 1;
        //     else
        //         dec[i] = 1;
        // }
        // for (int i = 0; i < n; i++)
        // {
        //     if (inc[i] > 1 && dec[i] > 1)
        //         ans = max(ans, inc[i] + dec[i]);
        // }
        // ans--;
        // return ans >= 3 ? ans : 0;
        int n = arr.size(), up = 0, down = 0, ans = 0;
        for (int i = 1; i < n; i++)
        {
            if (down && arr[i - 1] < arr[i] || arr[i - 1] == arr[i])
                up = down = 0;
            up += arr[i - 1] < arr[i];
            down += arr[i - 1] > arr[i];
            if (up && down)
                ans = max(ans, up + down + 1);
        }
        return ans;
    }
};
// @lc code=end
