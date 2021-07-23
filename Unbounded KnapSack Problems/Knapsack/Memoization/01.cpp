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
        int a = arr[n-1] + solve(arr,wt, W-wt[n-1], n, dp);
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
    int wt[]  = {1, 3, 4, 5};
    int val[] = {10, 40, 50, 70};
    int W = 14;
    int n = 4;
    cout<<solve(val, wt, W, n);
}
