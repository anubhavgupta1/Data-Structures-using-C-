#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// Memoization : top down approach
int countSubset(int *arr, int sum, int n, int **ans)
{
    if(sum==0)
    {
        return 0;
    }

    if(n==0)
    {
        return INT_MAX-1;
    }

    if(ans[n][sum]!=-1)
    {
        return ans[n][sum];
    }

    int result;
    if((arr[n-1] <= sum))
    {
        int a = 1 + countSubset(arr, sum-arr[n-1], n,ans);
        int b = countSubset(arr, sum, n-1,ans);
        result = min(a,b);
    }
    else
    {
        result = countSubset(arr, sum, n-1, ans);
    }
    ans[n][sum] = result;
    return result;
}



// Memoization : top down approach
int countSubset(int *arr, int sum, int n)
{
    int **ans;
    ans = new int* [n+1];
    for(int i = 0; i < n+1;i++)
    {
        ans[i] = new int[sum+1];
    }

    for(int i = 0; i < n+1;i++)
    {
        for(int j = 0; j < sum+1;j++)
        {
            ans[i][j] = -1;
        }
    }

    return countSubset(arr, sum, n, ans);
}


int main()
{
    int coins[] = {1, 2, 3};
    int n = 3;
    int sum = 5;
    cout<<countSubset(coins, sum,n);
}
