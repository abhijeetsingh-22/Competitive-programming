#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool ispossible(ll x, ll s, ll count)
{
    ll sum = s - x;
    count--;
    int B = 29;
    for (int b = B; b >= 0; b--)
    {
        if (((x>>b )&1) == 0){
            continue;}
        else
        {
            long times = min(count, (sum / (1L << b)));
            sum = sum - (times * (1 << b));
        }
    }
    return sum == 0;
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ll x, s, l = 1, r = 1e9+1;
        cin >> x >> s;
        while (l < r)
        {
            int m = (l + r) / 2;
            if (ispossible(x, s, m))
            {
                r = m-1;
            }
            else
            {
                l = m + 1;
            }
        }
        if (r > 1e9)
        {
            cout << -1 << endl;
        }
        else
            cout << r + 1 << endl;
    }
    return 0;
}