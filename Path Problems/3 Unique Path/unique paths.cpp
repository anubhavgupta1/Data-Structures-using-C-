#include<iostream>
using namespace std;

//Recursion
int numberOfPaths1(int m, int n)
{

    if (m == 1 || n == 1)
    {
        return 1;
    }

    int a = numberOfPaths1(m - 1, n);
    int b = numberOfPaths1(m, n - 1);
    return  a + b;
}

//Dynamic Programming
int numberOfPaths2(int m, int n)
{
    int dp[m][n];

    for(int i = 0; i<m; i++)
    {
        dp[i][0] = 1;
    }

    for(int i = 0; i<n; i++)
    {
        dp[0][i] = 1;
    }

    for(int i = 1; i<m; i++)
    {
        for(int j = 1; j<n; j++)
        {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[m-1][n-1];
}

int numberOfPaths3(int m, int n)
{
    int dp[n] = {1};
    dp[0] = 1;
    for(int i = 0; i<m; i++)
    {
        for(int j = 1; j<n; j++)
        {
            dp[j] = dp[j] + dp[j-1];
        }
    }
    return dp[n-1];
}

int main()
{
    cout << numberOfPaths3(3, 3);
}
