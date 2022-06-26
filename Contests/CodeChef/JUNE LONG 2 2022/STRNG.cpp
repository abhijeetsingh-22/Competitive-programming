#include <bits/stdc++.h>
using namespace std;
#define ll long long
int get_rem_gcd(int *pre, int *suf, int i, int n)
{
    if (i == 0)
        return suf[i + 1];
    if (i == n - 1)
        return pre[i - 1];
    return __gcd(pre[i - 1], suf[i + 1]);
}

void prepare_arrays(int *arr, int *pre, int *suf, int n)
{
    pre[0] = arr[0];
    suf[n - 1] = arr[n - 1];
    // pre array contains gcd from 0 to i position
    for (int i = 1; i < n; i++)
    {
        pre[i] = __gcd(pre[i - 1], arr[i]);
    }
    // suf array contains gcd from n-1 to j position
    for (int j = n - 2; j >= 0; j--)
    {
        suf[j] = __gcd(suf[j + 1], arr[j]);
    }
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, ans = 0, ones = 0;
        cin >> n;
        int arr[n], pre[n], suf[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        prepare_arrays(arr, pre, suf, n);
        for (int i = 0; i < n; i++)
        {
            int rem_gcd = get_rem_gcd(pre, suf, i, n);
            if (rem_gcd > 1)
                ans++;
        }
        cout << ans << endl;
    }
    return 0;
}