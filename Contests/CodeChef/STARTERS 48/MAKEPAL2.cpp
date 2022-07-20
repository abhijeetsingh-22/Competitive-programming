#include <bits/stdc++.h>
using namespace std;
#define ll long long
int count_ones(string s)
{
    int cnt = 0;
    for (auto c : s)
    {
        if (c == '1')
        {
            cnt++;
        }
    }
    return cnt;
}
// void filter(string &s, char e)
// {
//     cout << "filtering " << e << endl;
//     int i = 0, j = 0;
//     int n = s.size();
//     while (j < n)
//     {
//         if (s[j] != e)
//         {
//             cout << s[j] << "   ";
//             s[i++] = s[j++];
//         }
//         else
//             j++;
//     }
//     cout << "s=  " << s;
//     s[i] = '\0';
// }
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n;
        cin >> s;
        int ones = count_ones(s);
        // cout << "ones " << ones << endl;
        if (ones <= (n / 2))
        {
            for(int i=0;i<n-ones;i++)
            cout<<'0';
        }
        else
            for(int i=0;i<ones;i++)
            cout<<'1';

        cout << endl;
    }
    return 0;
}