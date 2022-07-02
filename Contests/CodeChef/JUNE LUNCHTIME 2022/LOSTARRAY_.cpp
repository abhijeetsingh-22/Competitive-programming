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
        ll n, t;
        vector<ll> b;
        b.reserve(1000000);
        cin >> n;
        for (int i = 0; i < n + 1; i++)
        {
            cin >> t;
            b.push_back(t);
        }

        if ((n & 1) == 1)
        {
            ll cumXor = 0;
            for (auto x : b)
            {
                cumXor = cumXor ^ x;
            }
            for (int i = 0; i < n + 1; i++)
            {
                b[i] = b[i] ^ cumXor;
            }
            sort(b.begin(), b.end());

            for (int i = 1; i < n + 1; i++)
            {
                cout << b[i] << " ";
            }
        
        }
        cout << endl;
    }
    return 0;
}