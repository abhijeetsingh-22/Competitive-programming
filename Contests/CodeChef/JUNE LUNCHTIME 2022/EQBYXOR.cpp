#include <bits/stdc++.h>
using namespace std;
#define ll long long
int setBit(int num, int i)
{
    int mask = 1 << i;
    return num | mask;
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, n, count = 0, f = 0, temp, j = 0;
        cin >> a >> b >> n;
        temp = a ^ b;
        while (temp > 0)
        {
            temp = temp >> 1;
            j++;
        }
        j--;

        if ((1 << j) >= n)
            count = -1;
        else
        {
            int x = a ^ b;
            j = 0;
            while (x)
            {
                int lastBit = (x & 1);
                if (lastBit)
                {
                    temp = setBit(f, j);
                    if (temp < n)
                    {
                        f = temp;
                    }
                    else
                    {
                        count++;
                        f = setBit(0, j);
                    }
                }
                j++;
                x = x >> 1;
            }
            if (f > 0)
                count++;
        }
        cout << count << endl;
    }
    return 0;
}