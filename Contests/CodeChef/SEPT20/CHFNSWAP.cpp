// https://www.codechef.com/SEPT20B/problems/CHFNSWAP
#include <iostream>
#include <math.h>
using namespace std;
#define ll long long

ll solve(ll n)
{
  ll s = n * (n + 1) / 2;
  return ((-1 + sqrt(1 + 4 * s)) / 2);
}

ll nc2(ll n)
{
  return (n * (n - 1) / 2);
}
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    ll n, ans = 0;
    cin >> n;
    if ((n * (n + 1) / 2) & 1)
    {
      cout << 0 << endl;
      continue;
    }
    ll x = solve(n);
    ans = (n - x);
    if ((n * (n + 1) / 2) == (x * (x + 1)))
    {
      ans += nc2(x) + nc2(n - x);
    }
    cout << ans << endl;
  }
  return 0;
}