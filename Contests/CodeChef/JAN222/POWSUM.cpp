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
        int n, sum = 0;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }
        int dif = pow(2, ceil(log2(sum))) - sum;
        if (dif == 0)
        {
            cout << 0 << endl;
            continue;
        }
        int csum = 0, psum = 0;
        int min = *min_element(a, a + n);
        int fac = (min + dif) / min;
        int i = 0, j = 0;
        for (; i < n; i++)
        {
            if (a[i] == min)
            {
                cout << 1 << endl;
                cout<<1<<" "<<fac<<endl;
                cout << i + 1 << endl;
                break;
            }
        }
    }
    return 0;
}