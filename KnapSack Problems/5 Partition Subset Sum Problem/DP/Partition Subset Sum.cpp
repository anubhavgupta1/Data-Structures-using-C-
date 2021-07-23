#include<iostream>
#include<vector>
#include<climits>
using namespace std;

//Partition a set into two subsets such
//that the difference of subset sums is minimum

int solve(int *arr, int sum, int n, vector<vector<bool>> &dp)
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
                bool a = dp[i-1][s-arr[i-1]];
                bool b = dp[i-1][s];
                dp[i][s] = a||b;
            }
            else
            {
                dp[i][s] = dp[i-1][s];
            }
        }
    }

    int diff = INT_MAX;
    for (int i = 0; i <= sum/2; i++)
    {
        if (dp[n][i] == true)
        {
            int temp = abs(sum - 2 * i);
            diff = min(diff, temp);
        }
    }
    return diff;
}

int solve(int *arr, int n)
{
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }
    vector< vector<bool>> dp(n+1, vector<bool> (sum+1));
    return solve(arr, sum, n, dp);
}


int main()
{
    int arr[] = {1, 2, 7};
    int n = 3;
    cout<<solve(arr, n);
}
