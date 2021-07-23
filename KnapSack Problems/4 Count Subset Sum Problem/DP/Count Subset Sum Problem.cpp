#include<iostream>
#include<vector>
using namespace std;

int solve(int *arr, int sum, int n, vector<vector<int>> &dp)
{
    for(int i = 0; i< sum+1; i++)
    {
        dp[0][i] = 0;
    }

    for(int i = 0; i< n+1; i++)
    {
        dp[i][0] = 1;
    }

    for(int i = 1; i< n+1; i++)
    {
        for(int s = 1; s< sum+1; s++)
        {
            if(arr[i-1]<=s)
            {
                int a = dp[i-1][s-arr[i-1]];
                int b = dp[i-1][s];
                dp[i][s] = a + b;
            }
            else
            {
                dp[i][s] = dp[i-1][s];
            }
        }
    }
    return dp[n][sum];
}

int solve(int *arr, int sum, int n)
{
    vector< vector<int>> dp(n+1, vector<int> (sum+1));
    return solve(arr, sum, n, dp);
}


int main()
{
    int arr[] = {1, 2, 3, 3};
    int n = 4;
    int sum = 6;
    cout<<solve(arr, sum,n);
}
