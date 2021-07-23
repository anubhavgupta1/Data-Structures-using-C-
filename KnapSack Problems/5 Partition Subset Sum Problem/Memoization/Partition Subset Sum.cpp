#include<iostream>
using namespace std;

//Partition a set into two subsets such
//that the difference of subset sums is minimum

int solve(int *arr, int curr_sum, int sum, int n, int **ans)
{
    if(ans[n][curr_sum]!=-1)
    {
        return ans[n][curr_sum];
    }
    if(n==0)
    {
        return abs(sum - 2 * curr_sum);
    }
    int left = solve(arr, curr_sum+arr[n-1], sum, n-1, ans);
    int right = solve(arr, curr_sum, sum, n-1, ans);
    ans[n][curr_sum] = min(left, right);
    return min(left, right);
}

int solve(int *arr, int n)
{
    int sum = 0;
    for(int i =0; i< n; i++)
    {
        sum = sum + arr[i];
    }

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

    return solve(arr, 0, sum, n, ans);
}

int main()
{
    int arr[] = {1, 2, 7};
    int n = 3;
    cout<<solve(arr, n);
}
