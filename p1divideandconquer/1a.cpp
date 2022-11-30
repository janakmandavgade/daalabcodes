// a) wap to find min and max ele in a given array by using min max algo based on divide and conquer strategy.
//  number of comparisons are reduced (3n/2 -2) (2n-1)
// b) wap to implement binary search .
// c)wap to implement closest pair of points
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// #include <bits/stdc++.h>
// using namespace std;

// int a[8] = {5, 6, 2, 3, 7, 12, 9, 2};
// int mn = 0, mx = 0,mid;

// void min_max(int i, int j)
// {
//     int min1, max1;
//     if (i == j)
//     {
//         mn = a[i];
//         mx = a[i];
//     }
//     else if (i == j - 1)
//     {
//         if (a[i] < a[j])
//         {
//             mn = a[i];
//             mx = a[j];
//         }
//         else
//         {
//             mn = a[j];
//             mx = a[i];
//         }
//     }
//     else
//     {
//         mid = (i + j) / 2;
//         min_max(i, mid);
//         min1 = mn;
//         max1 = mx;
//         min_max(mid + 1, j);
//         if(min1<mn){
//             mn = min1;
//         }
//         if(max1 > mx){
//             mx = max1;
//         }
//     }
// }

// int main()
// {
//     min_max(0,7);
//     printf("Min: %d\t Max: %d",mn,mx);
//     return 0;
// }

//////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////1b///////////////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;

int binsearch(int a[], int low, int high, int key)
{
    if (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (a[mid] == key)
        {
            return mid;
        }
        if (a[mid] > key)
        {
            return binsearch(a, low, mid - 1, key);
        }
        return binsearch(a, mid + 1, high, key);
    }
    return -1;
}

int main()
{
    int arr[] = {2, 3, 4, 10, 40};
    int x = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binsearch(arr, 0, n - 1, x);

    if (result == -1)
    {
        cout << "Not present" << endl;
    }
    else
    {
        cout << "present at idx" << result;
    }
    return 0;
}