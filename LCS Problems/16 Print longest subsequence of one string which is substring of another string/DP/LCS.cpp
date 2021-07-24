#include <bits/stdc++.h>
using namespace std;

string longestSubsequence(string X, string Y)
{

    // Stores the lengths of strings
    // X and Y
    int n = X.size();
    int m = Y.size();

    // Create a matrix
    vector<vector<int>> mat(n + 1, vector<int>(m + 1));

    // Initialize the matrix
    for(int i = 0; i < n + 1; i++)
    {
        for(int j = 0; j < m + 1; j++)
        {
            if (i == 0 || j == 0)
                mat[i][j] = 0;
        }
    }

    // Fill all the remaining rows
    for(int i = 1; i < n + 1; i++)
    {
        for(int j = 1; j < m + 1; j++)
        {

            // If the characters are equal
            if (X[i - 1] == Y[j - 1])
            {
                mat[i][j] = 1 + mat[i - 1][j - 1];
            }

            // If not equal, then
            // just move to next
            // in subsequence string
            else
            {
                mat[i][j] = mat[i - 1][j];
            }
        }
    }

    // Find maximum length of the
    // longest subsequence matching
    // substring of other string
    int len = 0, col = 0;

    // Iterate through the last
    // row of matrix
    for(int i = 0; i < m + 1; i++)
    {
        if (mat[n][i] > len)
        {
            len = mat[n][i];
            col = i;
        }
    }

    // Store the required string
    string res = "";
    int i = n;
    int j = col;

    // Backtrack from the cell
    while (len > 0)
    {

        // If equal, then add the
        // character to res string
        if (X[i - 1] == Y[j - 1])
        {
            res = X[i - 1] + res;
            i--;
            j--;
            len--;
        }
        else
        {
            i--;
        }
    }

    // Return the required string
    return res;
}

// Driver code
int main()
{
    string X = "ABCD";
    string Y = "ACDBDCD";

    cout << (longestSubsequence(X, Y));

    return 0;
}
