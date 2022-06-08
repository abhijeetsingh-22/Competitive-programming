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
        int n, x;
        cin >> n >> x;
        int a[n], sum = 0, count = 0, i;
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);

        for (i = n - 1; i >= 0; i--)
        {
            sum += a[i];
            count++;
            if (sum >= x)
            {
                cout << count;
                break;
            }
        }
        if (i < 0)
        {
            cout << -1;
        }
        cout << endl;
    }
    return 0;
}