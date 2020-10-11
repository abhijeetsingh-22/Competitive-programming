// https://www.codechef.com/OCT20B/problems/POSAND
#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool getPermutation(vector<int> &res, int n)
{
    if (n > 1 && (log2(n) == floor(log2(n)))) //check if n=2^x then premutation is not possible
        return false;
    res.push_back(1);
    for (int i = 2; i <= n; i++)
    {
        //for every i=2^x i+1 comes before i
        if (log2(i) == floor(log2(i)))
        {
            res.push_back(i + 1);
            res.push_back(i);
            i++;
        }
        else
            res.push_back(i);
    }
    // since 2&5==0 so when n>3 we need to reverse first 3 elements. {1&5>0}
    if (n > 3)
        reverse(res.begin(), res.begin() + 3);
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> res;
        res.reserve(n);
        if (getPermutation(res, n))
        {
            for (auto x : res)
            {
                cout << x << " ";
            }
        }
        else
            cout << -1;
        cout << "\n";
    }

    return 0;
}