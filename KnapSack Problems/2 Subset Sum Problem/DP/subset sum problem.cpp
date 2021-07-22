#include<iostream>
#include<vector>
using namespace std;

//Given a set of non-negative integers, and a value sum,
//determine if there is a subset of the given set with sum equal to given sum.

bool solve(int *arr, int sum, int n, vector<vector<bool>> &dp)
{
    for(int i = 0; i< sum+1; i++)
    {
        dp[0][i] = false;
    }

    for(int i = 0; i< n+1; i++)
    {
        dp[i][0] = true;
    }

    for(int i = 1; i< n+1; i++)
    {
        for(int s = 1; s< sum+1; s++)
        {
            if(arr[i-1]<=s)
            {
                int a = dp[i-1][s-arr[i-1]];
                int b = dp[i-1][s];
                dp[i][s] = a||b;
            }
            else
            {
                dp[i][s] = dp[i-1][s];
            }
        }
    }
    return dp[n][sum];
}

bool solve(int *arr, int sum, int n)
{
    vector< vector<bool>> dp(n+1, vector<bool> (sum+1));
    return solve(arr, sum, n, dp);
}


int main()
{
    int arr[] = {2, 3, 7, 8, 10};
    int n = 5;
    int sum = 11;
    cout<<solve(arr, sum,n);
}
