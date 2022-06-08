#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        int dsa1, dm1, toc1, dsa2, dm2, toc2;
        cin >> dsa1 >> toc1 >> dm1;
        cin >> dsa2 >> toc2 >> dm2;
        int t1 = dsa1 + dm1 + toc1, t2 = dsa2 + dm2 + toc2;
        // cout<<t1<<t2;
        int winner = 1;
        if (t2 > t1)
        {
            winner = 2;
        }
        else if (t1 == t2)
        {
            if (dsa2 > dsa1)
            {
                winner = 2;
            }
            else if (dsa1 == dsa2)
            {
                if (toc2 > toc1)
                {
                    winner = 2;
                }
                else if (toc1 == toc2)
                {
                    winner = 0;
                }
            }
        }
        if (winner == 1)
        {
            cout << "DRAGON";
        }
        else if (winner == 2)
        {
            cout << "SLOTH";
        }
        else
            cout << "TIE";
        cout<<endl;
    }
    return 0;
}