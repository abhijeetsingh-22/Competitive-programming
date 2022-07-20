#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        int idx = 1;
        int ans = 1;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        deque<int> todo, helper;
        for (int i = 0; i < n; i++)
        {
            todo.push_back(a[i]);
        }

        while (!todo.empty() or !helper.empty())
        {
            if (todo.empty())
            {
                swap(todo, helper);
                idx = 1;
                ans++;
            }
            int ele = todo.front();
            todo.pop_front();

            if (ele < idx)
            {
                helper.push_back(ele);
            }
            else
                idx++;
        }
        // for (int i = 0; i < n; i++)
        // {
        //     if (a[i] < idx)
        //     {
        //         int *val = upper_bound(a + i, a + n, idx);
        //         if (val == a + n)
        //         {
        //             idx = 1;
        //             ans++;
        //         }
        //         else
        //         {
        //             swap(a[i], *val);
        //             sort(a+i+1,a+n);
        //         }
        //     }

        //     idx++;
        // }
        cout << ans << endl;
    }
    return 0;
}