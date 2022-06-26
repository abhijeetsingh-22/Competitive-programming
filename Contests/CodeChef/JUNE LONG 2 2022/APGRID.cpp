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
        ll n, m;
        cin >> n >> m;
        ll dif, start;
        ll val;
        if (m >= n)
        {
            // if columns are greater than rows give smaller difference to the row
            //  then give differene to the columns
            dif = 1;
            start = 1;
            for (ll i = 0; i < n * m; i++)
            {
                val = start + (dif * (i % m));
                cout << val;
                if ((i + 1) % (m) == 0)
                {
                    cout << endl;
                    dif += 1;
                    start += (n + 1);
                }
                else
                    cout << " ";
            }
        }
        else
        {
            dif = m + 1;
            start = 1;
            for (ll i = 0; i < n * m; i++)
            {
                val = start + (dif * (i % m));
                cout << val;
                if ((i + 1) % (m) == 0)
                {
                    cout << endl;
                    dif += 1;
                    start += 1;
                }
                else
                    cout << " ";
            }
        }
    }
    return 0;
}