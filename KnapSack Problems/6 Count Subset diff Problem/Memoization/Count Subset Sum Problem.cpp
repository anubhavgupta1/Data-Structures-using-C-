#include<iostream>
#include<vector>
using namespace std;

// Memoization : top down approach
int countSubset(int *arr, int sum, int n, int **ans)
{
    if(sum==0)
    {
        return 1;
    }

    if(n==0)
    {
        return 0;
    }

    if(ans[n][sum]!=-1)
    {
        return ans[n][sum];
    }

    int result;
    if(arr[n-1] <= sum)
    {
        int a = countSubset(arr, sum-arr[n-1], n-1,ans);
        int b = countSubset(arr, sum, n-1,ans);
        result = a+b;
    }
    else
    {
        result = countSubset(arr, sum, n-1, ans);
    }
    ans[n][sum] = result;
    return result;
}



// Memoization : top down approach
int countSubset(int *arr, int diff, int n)
{
    int sum = 0;
    for(int i =0; i<n; i++)
    {
        sum = sum + arr[i];
    }
    if(sum+diff%2==1)
    {
        return 0;
    }
    else
    {
        sum = (sum + diff)/2;
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
}


int main()
{
    int arr[] = {1, 2, 3, 3};
    int n = 4;
    int diff = 3;
    cout<<countSubset(arr, diff,n);
}
