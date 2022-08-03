/*
 * @lc app=leetcode id=729 lang=cpp
 *
 * [729] My Calendar I
 */

// @lc code=start
class MyCalendar
{
public:
    // unordered_map<int, int> bookings;
    set<pair<int, int>> bookings;
    MyCalendar()
    {
    }

    bool book(int start, int end)
    {
        //
        // for (auto &[s, e] : bookings)
        // {
        //     if (!(e <= start or s >= end))
        //         return false;
        // }
        // bookings[start] = end;
        // return true;
        auto slot = bookings.lower_bound({start, end});
        if ((slot != bookings.end() and !(slot->first >= end)) or
            (slot != bookings.begin() and !(prev(slot)->second <= start)))
        {
            return false;
        }
        bookings.insert(make_pair(start, end));
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
// @lc code=end
