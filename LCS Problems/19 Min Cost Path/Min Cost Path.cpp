#include<iostream>
#include<climits>
using namespace std;

int minCost(int cost[3][3], int m, int n)
{
    if (m == -1 && n == -1)
    {
        return 0;
    }
    else if (n < -1 || m < -1)
    {
        return INT_MAX;
    }
    else
    {
        int a = minCost(cost, m - 1, n - 1);
        int b = minCost(cost, m - 1, n);
        int c = minCost(cost, m, n - 1);
        int ans = cost[m-1][n-1] + min(a, min(b, c));
        return ans;
    }
}

int minCost(int cost[3][3], int m, int n, int **dp)
{
    int ans;
    if(dp[m][n]!=-1)
    {
        return dp[m][n];
    }
    else if (m == -1 && n == -1)
    {
        return 0;
    }
    else if (n < -1 || m < -1)
    {
        return INT_MAX;
    }
    else
    {
        int a = minCost(cost, m - 1, n - 1);
        int b = minCost(cost, m - 1, n);
        int c = minCost(cost, m, n - 1);
        ans = cost[m-1][n-1] + min(a, min(b, c));
    }
    dp[m][n] = ans;
    return ans;
}

int minCostDP(int cost[3][3], int m, int n, int **dp)
{

    dp[0][0] = cost[0][0];

    for(int i = 1; i < m; i++)
    {
        dp[i][0] = dp[i-1][0] + cost[i][0];
    }

    for(int i = 1; i < n; i++)
    {
        dp[0][i] = dp[0][i-1] + cost[0][i];
    }

    for(int i = 1; i < m; i++)
    {
        for(int j = 1; j < n; j++)
        {
             int a  = dp[i][j-1];
             int b  = dp[i-1][j];
             int c  = dp[i-1][j-1];
             int d = min(a, min(b,c));
             dp[i][j] = d + cost[i][j];
        }
    }

    return dp[m-1][n-1];
}


int minCostDP(int cost[3][3])
{
    int m = 3;
    int n = 3;
    int **ans = new int* [m];
    for(int i = 0; i<m; i++)
    {
        ans[i] = new int[n];
    }
    return minCostDP(cost,m,n,ans);
}


void minCost(int cost[3][3])
{
    int m = 3;
    int n = 3;
    int **ans = new int* [m+1];
    for(int i = 0; i<m+1; i++)
    {
        ans[i] = new int[n+1];
    }

    for(int i = 0; i<m+1; i++)
    {
        for(int j = 0; j<n+1; j++)
        {
            ans[i][j] = -1;
        }
    }

    cout<<"Recursive : "<<minCost(cost, m, n)<<"\n";
    cout<<"Memoization : "<<minCost(cost, m, n, ans)<<"\n";
    cout<<"DP : "<<minCostDP(cost)<<"\n";
}


int main()
{
     int cost[3][3] = { { 1, 2, 3 },
                       { 4, 8, 2 },
                       { 1, 5, 3 } };

    minCost(cost);
    cout<<endl;
}
