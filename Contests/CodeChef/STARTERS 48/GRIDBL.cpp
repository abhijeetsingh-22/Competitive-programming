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
        int n, m;
        cin >> n >> m;
        int ans = 0;
        if (m % 2 != 0)
            ans += n;
        if (n % 2 != 0)
            ans += m;
        if (m % 2 != 0 and n % 2 != 0)
            ans--;
        cout << ans << endl;
    }
    return 0;
}