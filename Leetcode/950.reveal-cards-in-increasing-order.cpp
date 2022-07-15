/*
 * @lc app=leetcode id=950 lang=cpp
 *
 * [950] Reveal Cards In Increasing Order
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> deckRevealedIncreasing(vector<int> &deck)
    {
        int n = deck.size();
        vector<int> ans(n);
        deque<int> q;

        sort(deck.begin(), deck.end(), greater<int>());
        for (int x : deck)
        {

            if (!q.empty())
            {
                // int rear=;
                q.push_front(q.back());
                q.pop_back();
            }
            q.push_front(x);
        }
        int i = 0;
        while (!q.empty())
        {
            ans[i++] = q.front();
            q.pop_front();
        }

        return ans;
    }
};
// @lc code=end
