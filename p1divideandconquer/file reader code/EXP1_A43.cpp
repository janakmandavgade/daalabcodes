// Practical 1
// Aim : Stock price of capital A,B,C company want per day basis each stored in a file stock data "Stock Data" for a particular month.WAP read file and find min and max stock price using brute force approach. Also propose and implement an improved algorithm based on divide and conquer strategy. Compute the time complexity of brute force algo,divide and conquer algo.

// Brute force

#include <bits/stdc++.h>
using namespace std;

void read_record()
{

    vector<vector<string>> content;
    vector<string> row;
    string line, word;

    fstream file("data.csv", ios::in);
    if (file.is_open())
    {
        while (getline(file, line))
        {
            row.clear();

            stringstream str(line);

            while (getline(str, word, ','))
                row.push_back(word);
            content.push_back(row);
        }
    }
    else
        cout << "Could not open the file\n";
    
    
    vector<int> arr;

    for (int i = 0; i < content.size(); i++)
    {
        string s;
        for (int j = 0; j < content[i].size(); j++)
        {
            s+=content[i][j];
        }
        int s1 = stoi(s);
        arr.push_back(s1);
    }

    for (int i = 0; i < 23; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    int mn = INT_MAX;
    int mx = INT_MIN;
    for (int i = 0; i < 23; i++)
    {
        if (mn > arr[i])
        {
            mn = arr[i];
        }

        if (mx < arr[i])
        {
            mx = arr[i];
        }
    }
    cout << "Min:" << mn << endl;
    cout << "Max:" << mx << endl;
}

int main()
{
    int arr[] = {4, 6, 2, 9, 7, 8, 5, 3};

    read_record();
}

/////////////////////////////////////Brute force end//////////////////////////////////////////////


/////////////////////////////////////Divide and Conquer///////////////////////////////////////////
// #include <bits/stdc++.h>
// using namespace std;

// int a[8] = {5, 6, 2, 3, 7, 12, 9, 2};
// int mn = 0, mx = 0, mid;

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
//         if (min1 < mn)
//         {
//             mn = min1;
//         }
//         if (max1 > mx)
//         {
//             mx = max1;
//         }
//     }
// }

// int main()
// {
//     min_max(0, 7);
//     printf("Min: %d\t Max: %d", mn, mx);
//     return 0;
// }