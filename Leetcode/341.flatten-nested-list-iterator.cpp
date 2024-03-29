/*
 * @lc app=leetcode id=341 lang=cpp
 *
 * [341] Flatten Nested List Iterator
 */

// @lc code=start
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
#include <bits/stdc++.h>
using namespace std;
class NestedIterator
{
private:
    queue<int> q;
    void flatten(NestedInteger &item)
    { // base case
        if (item.isInteger())
        {
            q.push(item.getInteger());
            return;
        }
        // recursive case
        vector<NestedInteger> list = item.getList();
        for (auto x : list)
        {
            flatten(x);
        }
    }

public:
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        for (auto x : nestedList)
        {
            flatten(x);
        }
    }

    int next()
    {
        int data = q.front();
        q.pop();
        return data;
    }

    bool hasNext()
    {
        return !q.empty();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
// @lc code=end
