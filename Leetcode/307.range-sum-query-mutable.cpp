/*
 * @lc app=leetcode id=307 lang=cpp
 *
 * [307] Range Sum Query - Mutable
 */

// @lc code=start
class NumArray
{
    int seg[4 * 100005];
    static inline int n;

public:
    NumArray(vector<int> &nums)
    {
        n = nums.size();
        build(0, 0, n - 1, nums);
    }
    void build(int idx, int low, int high, vector<int> &nums)
    {
        if (low == high)
        {
            seg[idx] = nums[low];
            return;
        }
        int mid = (low + high) / 2;
        build(2 * idx + 1, low, mid, nums);
        build(2 * idx + 2, mid + 1, high, nums);
        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }
    int query(int idx, int low, int high, int l, int r)
    {
        if (low >= l and high <= r)
        {
            return seg[idx];
        }
        if (high < l or low > r)
            return 0;
        int mid = (low + high) / 2;
        int left_sum = query(2 * idx + 1, low, mid, l, r);
        int right_sum = query(2 * idx + 2, mid + 1, high, l, r);
        return left_sum + right_sum;
    }
    void update(int index, int val, int seg_idx = 0, int low = 0, int high = n - 1)
    {
        if (low == high)
        {
            seg[seg_idx] = val;
            return;
        }
        int mid = (low + high) / 2;
        if (index <= mid)
            update(index, val, 2 * seg_idx + 1, low, mid);
        else
            update(index, val, 2 * seg_idx + 2, mid + 1, high);
        seg[seg_idx] = seg[2 * seg_idx + 1] + seg[2 * seg_idx + 2];
    }

    int sumRange(int left, int right)
    {
        return query(0, 0, n - 1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
// @lc code=end
