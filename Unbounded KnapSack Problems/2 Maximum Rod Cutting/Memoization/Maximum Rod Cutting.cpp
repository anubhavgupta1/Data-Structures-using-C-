#include<iostream>
#include<vector>
using namespace std;

int solve(int *price, int *length, int max_len, int n, vector<vector<int>> &dp)
{
    if(dp[n][max_len]!=-1)
    {
        return dp[n][max_len];
    }

    if(max_len==0||n==0)
    {
        return 0;
    }

    int ans;
    if(length[n-1]<=max_len)
    {
        int a = price[n-1] + solve(price,length, max_len-length[n-1], n, dp);
        int b = solve(price,length, max_len, n-1, dp);
        ans = max(a,b);
    }
    else
    {
        ans = solve(price,length, max_len, n-1, dp);
    }

    dp[n][max_len] = ans;
    return ans;
}

int solve(int *price, int *length, int max_len, int n)
{
     vector<vector<int>> dp(n+1, vector<int>(max_len+1, -1));
     return solve(price, length, max_len, n, dp);
}


int main()
{
    int price[] = { 1, 5, 8, 9, 10, 17, 17, 20 };
    int n = 8;
    int *length = new int [n];
    for (int i = 0; i < n; i++)
    {
        length[i] = i + 1;
    }
    int max_len = n;
    cout<<solve(price, length, max_len, n);
}
