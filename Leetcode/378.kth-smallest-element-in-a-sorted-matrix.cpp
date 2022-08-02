/*
 * @lc app=leetcode id=378 lang=cpp
 *
 * [378] Kth Smallest Element in a Sorted Matrix
 */

// @lc code=start
class Solution
{
private:
    static int kth_smallest_maxheap(vector<vector<int>> &matrix, int k)
    {
        priority_queue<int> pq;
        for (auto &row : matrix)
        {
            for (auto &e : row)
            {
                pq.push(e);
                if (pq.size() > k)
                    pq.pop();
            }
        }

        return pq.top();
    }
    static int kth_smallest_binary_search(vector<vector<int>> &matrix, int k)
    {
        int n = matrix.size();
        int low = matrix[0][0];
        int high = matrix[n - 1][n - 1];
        int ans = -1;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (count_less_than_or_equal(matrix, mid) >= k)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
    static int count_less_than_or_equal(vector<vector<int>> &matrix, int num)
    {
        int count = 0;
        int n = matrix.size();
        int col = n - 1;

        for (int row = 0; row < n; row++)
        {
            while (col >= 0 and matrix[row][col] > num)
                col--;
            count += (col + 1);
        }
        return count;
    }

public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        // return kth_smallest_maxheap(matrix, k);
        return kth_smallest_binary_search(matrix, k);
    }
};
// @lc code=end
