/*
 * @lc app=leetcode id=315 lang=cpp
 *
 * [315] Count of Smaller Numbers After Self
 */

// @lc code=start

class Solution
{
private:
    static void merge(vector<pair<int, int>> &nums, int s, int e, vector<int> &ans)
    {

        int mid = (s + e) / 2;
        int left_idx = s, right_idx = mid + 1;
        vector<pair<int, int>> temp;
        int count_smaller_than_left = 0;

        while (left_idx <= mid and right_idx <= e)
        {

            if (nums[left_idx].second <= nums[right_idx].second)
            {
                temp.push_back(nums[left_idx]);
                ans[nums[left_idx].first] += count_smaller_than_left;
                left_idx++;
            }
            else
            {
                temp.push_back(nums[right_idx]);
                count_smaller_than_left++;
                right_idx++;
            }
        }

        while (left_idx <= mid)
        {
            temp.push_back(nums[left_idx]);
            ans[nums[left_idx].first] += count_smaller_than_left;
            left_idx++;
        }
        while (right_idx <= e)
        {
            temp.push_back(nums[right_idx]);
            right_idx++;
        }

        for (int idx = s; idx <= e; idx++)
        {
            nums[idx] = temp[idx - s];
        }
    }
    static void merge_sort_and_count(vector<pair<int, int>> &nums, int s, int e, vector<int> &ans)
    {
        if (s >= e)
            return;
        int mid = (s + e) / 2;
        merge_sort_and_count(nums, s, mid, ans);
        merge_sort_and_count(nums, mid + 1, e, ans);

        merge(nums, s, e, ans);
    }

public:
    vector<int> countSmaller(vector<int> &nums)
    {
        // Brute force O(N^2)
        int n = nums.size();
        vector<int> ans(n, 0);

        // for (int i = 0; i < n; i++)
        //     for (int j = i + 1; j < n; j++)
        //     {
        //         if (nums[j] < nums[i])
        //             ans[i]++;
        //     }

        // idx,val pair
        vector<pair<int, int>> new_nums;
        new_nums.reserve(n);
        for (int i = 0; i < n; i++)
            new_nums.push_back({i, nums[i]});

        merge_sort_and_count(new_nums, 0, n - 1, ans);
        // count(nums, ans);
        return ans;
    }
};
// @lc code=end
