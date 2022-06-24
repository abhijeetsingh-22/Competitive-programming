#include <bits/stdc++.h>
using namespace std;
#define ll long long
void prime_sieve(int *a)
{
    int n = 100000;
    // mark all the odd numbers as prime
    for (ll i = 3; i < n; i += 2)
    {

        a[i] = 1;
    }
    // for all prime numbers mark its multiples as not prime
    for (ll i = 3; i < n; i++)
    {
        if (a[i] == 1)
        {
            for (ll j = i * i; j < n; j += i)
            {
                a[j] = 0;
            }
        }
    }
    a[0] = 0;
    a[2] = 1;
    a[1] = 0;
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int primes[100000] = {0};
    int n = 100;
    cin >> n;
    prime_sieve(primes);
    for (int i = 0; i < n; i++)
    {
        if (primes[i])
        {
            cout << i << " ";
        }
    }
    return 0;
}