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
        string ans;
        int n;
        cin >> n;
        if ((n & 1) == 0)
        {
            for (int i = 0; i < (n - 4) / 2; i++)
            {
                ans.push_back('0');
            }
            ans.append("1001");
            for (int i = 0; i < (n - 4) / 2; i++)
            {
                ans.push_back('0');
            }
        }
        else
        {
            for (int i = 0; i < (n - 3) / 2; i++)
            {
                ans.push_back('0');
            }
            ans.append("010");
            for (int i = 0; i < (n - 3) / 2; i++)
            {
                ans.push_back('0');
            }
        }
        cout << ans << endl;
    }
    return 0;
}