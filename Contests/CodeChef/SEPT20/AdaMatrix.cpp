// https://www.codechef.com/problems/ADAMAT
#include <iostream>
using namespace std;

int minT(int A[], int n)
{
    bool inPlace[n];
    for (int i = 0; i < n; i++)
    {
        if (A[i] == i + 1)
            inPlace[i] = true;
        else
            inPlace[i] = false;
    }
    int count = 0;
    for (int i = n - 1; i >= 1; i--)
    {
        if (!inPlace[i])
        {
            count++;
            for (int j = i; j >= 1; j--)
            {
                inPlace[i] = !inPlace[i];
            }
        }
    }
    return count;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, A[64 * 64];
        cin >> n;
        for (int i = 0; i < n * n; i++)
            cin >> A[i];
        cout << minT(A, n) << endl;
    }
    return 0;
}