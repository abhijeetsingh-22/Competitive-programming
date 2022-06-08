#include <iostream>
#include <climits>
using namespace std;
void bubble_sort(int arr[])
{
    int n = 10;
    int max;
    for (int i = 0; i < n; i++)
    {
        max = 0;
        for (int j = 0; j < n - i; j++) //traverse over subarray 0-->n-i
        {
            if (arr[j] > arr[max]) //find the index of the max element in the sub array
            {
                max = j;
            }
        }
        swap(arr[n - i - 1], arr[max]); //take the largest element int sub array to last idx
    }
}
void selection_sort(int *arr)
{
    int n = 10;
    int min;
    for (int i = 0; i < n; i++)
    {
        min = i;
        //traverse over sub array i-->n-1
        for (int j = i; j < n; j++)
        {
            //find the index of the smallest element in the sub array
            if (arr[min] > arr[j])
                min = j;
        }
        // swap the smallest element with the first element in the sub array
        swap(arr[i], arr[min]);
    }
}
void insertion_sort(int *arr)
{
    int n = 10;
    int temp;
    // iterate over all the elements in the array
    for (int i = 0; i < n; i++)
    {
        int j = i - 1;
        temp = arr[i];
        // for each element find its correct positon
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        // place the element at its correct postiton
        arr[j + 1] = temp;
    }
}

int main()
{
    int a[10] = {1, 8, 5, 2, 9, 1, 89, 65, 2, 13};
    insertion_sort(a);
    for (int i = 0; i < 10; i++)
        cout << a[i] << "  ";
    return 0;
}