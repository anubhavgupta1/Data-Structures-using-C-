#include<iostream>
using namespace std;

int solve(int *arr, int *wt, int W, int n)
{
    if(W==0||n==0)
    {
        return 0;
    }

    int ans;
    if(wt[n-1]<=W)
    {
        int a = arr[n-1] + solve(arr,wt, W-wt[n-1], n-1);
        int b = solve(arr,wt, W-wt[n-1], n-1);
        ans = max(a,b);
    }
    else
    {
        ans = solve(arr,wt, W-wt[n-1], n-1);
    }
    return ans;
}

int main()
{
    int wt[] = {10,20,30};
    int arr[] = {60, 100, 120};
    int W = 50;
    int n = 3;
    cout<<solve(arr, wt, W, n);
}
