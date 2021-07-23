#include<iostream>
using namespace std;

int solve(int *arr, int sum, int n)
{
    if(sum==0)
    {
        return 1;
    }

    if(n==0)
    {
        return 0;
    }
    int ans;
    if(arr[n-1]<=sum)
    {
        int a = solve(arr, sum-arr[n-1], n);
        int b = solve(arr, sum, n-1);
        ans = a+b;
    }
    else
    {
        ans = solve(arr, sum, n-1);
    }

    return ans;
}

int main()
{
    int coins[] = {1, 2, 3};
    int n = 3;
    int sum = 5;
    cout<<solve(coins, sum,n);
}
