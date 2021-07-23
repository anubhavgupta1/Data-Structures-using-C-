#include<iostream>
#include<vector>
using namespace std;

int solve(int *wt, int *val, int W, int n, vector< vector<int>>& ans)
{
    for(int i = 0;i< W+1; i++)
    {
        ans[0][i] = 0;
    }

    for(int i = 0;i< n+1; i++)
    {
        ans[i][0] = 0;
    }

    for(int i = 1; i < n+1; i++)
    {
        for(int w = 1; w < W +1; w++ )
        {
            if(wt[i-1] <= w) //if array weight is less than or equal to current weight
            {
                int a = val[i-1] + ans[i][w - wt[i-1]];
                int b = ans[i-1][w];
                ans[i][w] = max(a,b);
            }
            else
            {
                ans[i][w] = ans[i-1][w];
            }
        }
    }
    return ans[n][W];
}


int solve(int *arr, int *wt, int W, int n)
{
     vector< vector<int>> dp(n+1, vector<int> (W+1));
     return solve(wt, arr, W, n, dp);
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
