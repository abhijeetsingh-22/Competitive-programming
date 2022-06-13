/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start

class Solution
{
public:
    int trap(vector<int> &height)
    {
        // Naive approach T->O(n^3)
        // int n = height.size(), ans = 0;
        // for (int i = 1; i < n - 1; i++)
        // {
        //     // find highest on left
        //     int left = height[i];
        //     for (int j = i - 1; j >= 0; j--)
        //         left = max(left, height[j]);

        //     // find height on the right
        //     int right = height[i];
        //     for (int j = i + 1; j < n; j++)
        //         right = max(right, height[j]);
        //     ans += min(left, right) - height[i];
        // }
        // return ans;

        // Better approach T-> O(n) S->O(n)

        // int n = height.size(), ans = 0;
        // vector<int> maxLheight(100000), maxRheight(100000);
        // maxLheight[0] = height[0];
        // for (int i = 1; i < n; i++)
        // {
        //     maxLheight[i] = max(maxLheight[i - 1], height[i]);
        // }

        // maxRheight[n - 1] = height[n - 1];
        // for (int i = n - 2; i >= 0; i--)
        // {
        //     maxRheight[i] = max(maxRheight[i + 1], height[i]);
        // }
        // for (int i = 0; i < n; i++)
        // {
        //     ans += min(maxLheight[i], maxRheight[i]) - height[i];
        // }
        // return ans;

        // Best approach T-> O(n) S->O(1)
        int n = height.size();
        int l = 0, r = n - 1, lMax = 0, rMax = 0, ans = 0;
        while (l <= r)
        {
            if (height[l] <= height[r])
            {
                if (height[l] >= lMax)
                {
                    lMax = height[l];
                }
                else
                    ans += lMax - height[l];
                l++;
            }
            else
            {
                if (height[r] >= rMax)
                {
                    rMax = height[r];
                }
                else
                {
                    ans += rMax - height[r];
                }
                r--;
            }
        }
        return ans;
    }
};
// @lc code=end
