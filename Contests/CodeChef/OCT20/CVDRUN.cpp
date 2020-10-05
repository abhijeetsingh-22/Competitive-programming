// https://www.codechef.com/OCT20B/problems/CVDRUN
#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool willGetInfected(int n, int k, int x, int y)
{

    int count[n] = {0};
    while (1)
    {
        if (count[x]) //check if virus goes to a city again
        {
            return false;
        }
        count[x]++;
        x = (x + k) % n;
        if (count[y]) //check if it reaches the destination city
        {
            return true;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, x, y;
        cin >> n >> k >> x >> y;
        if (willGetInfected(n, k, x, y))
            cout << "YES";
        else
            cout << "NO";
        cout << "\n";
    }
    return 0;
}