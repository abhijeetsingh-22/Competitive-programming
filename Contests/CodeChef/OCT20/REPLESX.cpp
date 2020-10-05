// https://www.codechef.com/OCT20B/problems/REPLESX
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int getMinOperations(vector<int> &A, int n, int x, int p, int k)
{
    // reduce for 0 based indexing
    p--;
    k--;
    sort(A.begin(), A.end());
    if (A[p] == x) //check if condition is met initially
        return 0;
    if (k == p)
    {
        if (x < A[p])
        {
            int i;
            for (i = p; i >= 0; i--)
            {
                if (A[i] <= x)
                    break;
            }
            return p - i;
        }
        else
        {
            int i;
            for (i = p; i < n; i++)
            {
                if (A[i] >= x)
                    break;
            }
            return i - p;
        }
    }
    if (k > p)
    {
        if (A[p] < x) //only smaller/equal number can be placed on that place in sorted array
            return -1;
        else
        {
            int i;
            for (i = p; i >= 0; i--)
            {
                if (A[i] <= x)
                    break;
            }
            return p - i;
        }
    }
    else
    {
        if (A[p] > x) //only greater/equal number can be placed on that place;
            return -1;
        else
        {
            int i;
            for (i = p; i < n; i++)
            {
                if (A[i] >= x)
                    break;
            }
            return i - p;
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
        vector<int> A;
        int n, x, p, k, temp;
        cin >> n >> x >> p >> k;
        A.reserve(n);
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            A.push_back(temp);
        }
        cout << getMinOperations(A, n, x, p, k) << "\n";
    }
    return 0;
}