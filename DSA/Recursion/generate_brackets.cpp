#include <bits/stdc++.h>
using namespace std;
#define ll long long
void generate_brackets(int n, int i, char *out, int open, int close)
{ // base case
    if (i == ((2 * n)))
    {
        // out[i] = ')';
        out[i ] = '\0';
        cout << out << endl;
    }

    // recursive case

    if (open < n)
    {
        out[i] = '(';
        generate_brackets(n, i + 1, out, open + 1, close);
    }
    if (close < open)
    {
        out[i] = ')';
        generate_brackets(n, i + 1, out, open, close + 1);
    }


}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    char output[100];
    int n;
    cin >> n;
    generate_brackets(n, 0, output, 0, 0);
    return 0;
}