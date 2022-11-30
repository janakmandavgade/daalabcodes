// Given 2 strings, find longest common subsequence between them & print it

#include <bits/stdc++.h>
using namespace std;

void printMatrix(vector<vector<int>> &v)
{
    for (auto i : v)
    {
        for (auto j : i)
        {
            if (j < 10)
                cout << j << "  ";
            else
                cout << j << " ";
        }
        cout << endl;
    }
    cout << endl << endl;
}

void printLCS(vector<vector<int>> &v, vector<vector<int>> &direction, string s1, string s2)
{
    string ans;

    int i = s1.size();
    int j = s2.size();

    // cout<<"Starting index : "<<i<<" "<<j<<endl;

    int loop = 100;

    while (loop--)
    {
        if (i == 0 || j == 0)
        {
            break;
        }

        if (s1[i - 1] == s2[j - 1])
        {
            // cout<<i<<j<<endl;
            ans += s1[i - 1];
            i--;
            j--;
        }
        else if (direction[i][j] == 1)
        {
            i--;
        }
        else if (direction[i][j] == 3)
        {
            j--;
        }
    }

    reverse(ans.begin(), ans.end());

    cout << ans << endl;

    cout << "Length of Sequence : " << ans.size() << endl;

    // cout<<endl<<"Ending...."<<endl;
}

int main()
{
    string s1;
    string s2;

    // s1="BCDAACD";
    // s2="ACDBAC";

    s1="01111";
    s2="010101";

    // s1 = "AGCCCTAAGGGCTACCTAGCTT";
    // s2 = "GACAGCCTACAAGCGTTAGCTTG";

    int n1 = s1.size();
    int n2 = s2.size();

    // cin>>s1>>s2;

    vector<vector<int>> arr(n1 + 1, vector<int>(n2 + 1, 0));

    vector<vector<int>> direction(n1 + 1, vector<int>(n2 + 1, 0));
    // 1 for top
    // 2 for diagonal
    // 3 for left

    // printMatrix(arr);

    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
        {
            char c1 = s1[i - 1];
            char c2 = s2[j - 1];

            if (c1 == c2)
            {
                arr[i][j] = 1 + arr[i - 1][j - 1];
                direction[i][j] = 2;
            }
            else if (arr[i - 1][j] > arr[i][j - 1])
            {
                arr[i][j] = arr[i - 1][j];
                direction[i][j] = 1;
            }
            else
            {
                arr[i][j] = arr[i][j - 1];
                direction[i][j] = 3;
            }
        }
    }

    cout << "Count Matrix" << endl;
    printMatrix(arr);

    cout << "Direction Matrix" << endl;
    printMatrix(direction);

    cout << "Longest Common Subsequence : ";
    printLCS(arr, direction, s1, s2);
}