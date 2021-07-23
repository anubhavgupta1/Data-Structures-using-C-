#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int solve(int *arr, int sum, int n, vector<vector<int>> &dp)
{
    for(int i = 0; i< sum+1; i++)
    {
        dp[0][i] = INT_MAX-1;
    }

    for(int i = 1; i< n+1; i++)
    {
        dp[i][0] = 0;
    }

    for(int i = 1; i< n+1; i++)
    {
        for(int s = 1; s< sum+1; s++)
        {
            if(arr[i-1]<=s)
            {
                int a = 1 + dp[i][s-arr[i-1]];
                int b = dp[i-1][s];
                dp[i][s] = min(a,b);
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
    int coins[] = {1, 2, 3};
    int n = 3;
    int sum = 5;
    cout<<solve(coins, sum,n);
}
