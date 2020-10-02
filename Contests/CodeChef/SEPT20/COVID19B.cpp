//https://www.codechef.com/SEPT20B/problems/COVID19B
#include <iostream>
using namespace std;

void minMaxInfected(int *A, int n)
{
    int infected = 1, maxSource, minSource, Imax = 1, Imin = n, pos, source;

    for (int i = 0; i < n; i++)
    {
        source = maxSource = minSource = A[i];
        infected = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < source)
                minSource = min(A[j], minSource);
        }
        for (int j = 0; j < i; j++)
        {
            if (A[j] > minSource)
            {
                infected++;
                maxSource = max(maxSource, A[j]);
            }
        }
        source = max(source, maxSource);
        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < source)
                infected++;
        }

        Imax = max(infected, Imax);
        Imin = min(infected, Imin);
    }
    cout << Imin << " " << Imax << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, A[5];
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> A[i];
        minMaxInfected(A, n);
    }
    return 0;
}