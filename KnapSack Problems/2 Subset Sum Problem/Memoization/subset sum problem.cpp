#include<iostream>
#include<vector>
using namespace std;

//Given a set of non-negative integers, and a value sum,
//determine if there is a subset of the given set with sum equal to given sum.

bool solve(int *arr, int sum, int n, vector<vector<bool>> &dp)
{
    if(dp[n][sum]!=-1)
    {
       return dp[n][sum];
    }

    if(sum==0)
    {
        return true;
    }

    if(n==0)
    {
        return false;
    }

    int ans;
    if(arr[n-1]<=sum)
    {
        int a = solve(arr, sum-arr[n-1], n-1, dp);
        int b = solve(arr, sum, n-1, dp);
        ans = a||b;
    }
    else
    {
        ans = solve(arr, sum, n-1, dp);
    }

    dp[n][sum] = ans;
    return ans;
}

bool solve(int *arr, int sum, int n)
{
    vector<vector<bool>> dp(n+1, vector<bool>(sum+1, -1));
    return solve(arr, sum, n, dp);
}


int main()
{
    int arr[] = {2, 3, 7, 8, 10};
    int n = 5;
    int sum = 11;
    cout<<solve(arr, sum,n);
}
