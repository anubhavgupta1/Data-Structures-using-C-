#include<iostream>
#include<vector>
using namespace std;

int solve(int *arr, int *wt, int W, int n, vector<vector<int>> &dp)
{
    if(dp[n][W]!=-1)
    {
        return dp[n][W];
    }

    if(W==0||n==0)
    {
        return 0;
    }

    int ans;
    if(wt[n-1]<=W)
    {
        int a = arr[n-1] + solve(arr,wt, W-wt[n-1], n-1, dp);
        int b = solve(arr,wt, W, n-1, dp);
        ans = max(a,b);
    }
    else
    {
        ans = solve(arr,wt, W, n-1, dp);
    }

    dp[n][W] = ans;
    return ans;
}

int solve(int *arr, int *wt, int W, int n)
{
     vector<vector<int>> dp(n+1, vector<int>(W+1, -1));
     return solve(arr, wt, W, n, dp);
}


int main()
{
    int wt[] = {10,20,30};
    int arr[] = {60, 100, 120};
    int W = 50;
    int n = 3;
    cout<<solve(arr, wt, W, n);
}
