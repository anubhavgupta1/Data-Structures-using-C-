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
        int a = solve(arr, sum-arr[n-1], n-1);
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
    int arr[] = {1, 2, 3, 3};
    int n = 4;
    int sum = 6;
    cout<<solve(arr, sum,n);
}
