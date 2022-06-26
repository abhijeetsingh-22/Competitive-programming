#include <bits/stdc++.h>
using namespace std;
#define ll long long
int partition(int *arr, int start, int end)
{
    int i = start - 1, j = start, p = end;
    while (j <= end)
    {
        if (arr[j] < arr[p])
        {
            i++;
            swap(arr[i], arr[j]);
        }
        j++;
    }
    swap(arr[i + 1], arr[p]);
    return i + 1;
}
void quick_sort(int *arr, int start, int end)
{
    // base case
    if (start >= end)
    {
        return;
    }

    // recursive case
    int p = partition(arr, start, end);
    quick_sort(arr, start, p - 1);
    quick_sort(arr, p + 1, end);
}
int main()
{
    int arr[] = {1, 4, 6, 3, 2, 7, 5, 1, 10, 9};
    int n = sizeof(arr) / sizeof(int);
    quick_sort(arr, 0, n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}