/*
 * @lc app=leetcode id=852 lang=cpp
 *
 * [852] Peak Index in a Mountain Array
 */

// @lc code=start
class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        // O(log(n)) solution
        int lb = 0, ub = arr.size() - 1;
        while (lb <= ub)
        {
            int mid = (lb + ub) / 2;
            if (arr[mid] < arr[mid + 1])
                lb = mid + 1;
            else if (arr[mid] < arr[mid - 1])
                ub = mid - 1;
            else
                return mid;
        }

        // O(n) solution
        // int i;
        // for (i = 0; i < arr.size(); i++)
        // {
        //     if (arr[i] > arr[i + 1])
        //         break;
        // }
        // return i;
        return 0;
    }
};
// @lc code=end
