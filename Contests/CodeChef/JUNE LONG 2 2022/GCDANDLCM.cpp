// https://www.codechef.com/submit/GCDANDLCM
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll ans = 0;
        for (ll a = 1; a * a <= n; a++)
        {
            for (ll lcm_a = a; lcm_a * lcm_a <= n; lcm_a += a)
            {
                // cout << lcm_a;
                ll a_sq = a * a;
                ll lcm_a_sq = lcm_a * lcm_a;
                ll num = lcm_a_sq * (n - lcm_a_sq - a_sq);
                if (num <= 0)
                    continue;
                ll denom=(lcm_a_sq + a_sq);
                if (num % denom != 0)
                    continue;
                ll b_sq = (ll)((num / denom));
                ll b = (ll)sqrt(b_sq);
                if (b * b != b_sq)
                    continue;
                ll gcd_ab = __gcd(a, b);
                ll lcm_ab = (a * b) / gcd_ab;
                ll val = a_sq + b_sq + gcd_ab * gcd_ab +lcm_a*lcm_a;
                if (val == n)
                    ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}