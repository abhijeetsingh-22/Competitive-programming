// https://www.codechef.com/JAN222C/problems/CRYCOLR
#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool is_sorted(int b[3][3], int n)
{

    return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, count = 0;
        int b[3][3];
        cin >> n;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                cin >> b[i][j];

        if (b[0][0] == n && b[1][1] == n && b[2][2] == n)
        {
            cout << 0 << endl;
            continue;
        }
        else
        {
            int x = b[1][0] + b[2][0] + b[2][1];
            int y = b[0][1] + b[0][2] + b[1][2];
            cout << max(x, y) << endl;
        }
    }

    return 0;
}
