#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int low, int high)
{

    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void qs(int arr[], int low, int high)
{

    if (low < high)
    {
        int pi = partition(arr, low, high);
        qs(arr, low, pi - 1);
        qs(arr, pi + 1, high);
    }
}
int main()
{
    int arr[] = {67, 90, 65, 54, 99, 56};
    qs(arr, 0, 5);
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}