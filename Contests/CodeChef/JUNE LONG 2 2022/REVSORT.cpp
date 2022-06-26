// https://www.codechef.com/JUNE222B/problems/REVSORT
#include <bits/stdc++.h>
using namespace std;
#define ll long long
// min size of subarray is 2 so if we can take the max element to its position by
// pair wise swapping then we can find the minimum x required

bool is_sort_possible(int *arr, int n, int x)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            if (arr[i] + arr[i + 1] <= x)
            {
                swap(arr[i], arr[i + 1]);
            }
            else
                return false;
        }
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int x, n;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        if (is_sort_possible(arr, n, x))
        {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }
    return 0;
}