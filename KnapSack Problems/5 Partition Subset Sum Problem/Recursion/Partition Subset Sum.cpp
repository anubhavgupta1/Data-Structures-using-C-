#include<iostream>
using namespace std;

//Partition a set into two subsets such
//that the difference of subset sums is minimum

int solve(int *arr, int curr_sum, int sum, int n)
{
    if(n==0)
    {
        return abs(sum - 2 * curr_sum);
    }
    int left = solve(arr, curr_sum+arr[n-1], sum, n-1);
    int right = solve(arr, curr_sum, sum, n-1);
    return min(left, right);
}

int solve(int *arr, int n)
{
    int sum = 0;
    for(int i =0; i< n; i++)
    {
        sum = sum + arr[i];
    }
    return solve(arr, 0, sum, n);
}

int main()
{
    int arr[] = {1, 2, 7};
    int n = 3;
    cout<<solve(arr, n);
}
