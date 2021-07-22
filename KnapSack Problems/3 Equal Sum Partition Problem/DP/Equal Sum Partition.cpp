#include<iostream>
#include<vector>
using namespace std;

//Partition problem is to determine whether a given set can be partitioned
//into two subsets such that the sum of elements in both subsets is the same.

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
    int arr[] = {1, 5, 11, 5};
    int n = 4;
    int sum = 0;
    for(int i = 0; i<n ; i++)
    {
        sum = sum + arr[i];
    }
    if(sum%2==1)
    {
        cout<<false;
    }
    else
    {
        cout<<solve(arr,sum/2,n);
    }
}
