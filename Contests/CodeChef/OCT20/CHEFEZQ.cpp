//https://www.codechef.com/OCT20B/problems/CHEFEZQ
#include <iostream>
#include <math.h>
using namespace std;
#define ll long long
ll firstFree(ll q[], ll n, ll k)
{
    ll i = 0, work = 0;
    for (i = 0; i < n; i++)
    {
        work += q[i]; //work for that day
        if (work - k < 0)
        {
            return i + 1;
        }
        work -= k; //sub work done
    }
    if (work > 0)
        i += floor(work / k) + 1; // days req to complete work after n days
    return i;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        ll q[100000];
        cin >> n >> k;
        for (int i = 0; i < n; i++)
        {
            cin >> q[i];
        }
        cout << firstFree(q, n, k) << endl;
    }
    return 0;
}