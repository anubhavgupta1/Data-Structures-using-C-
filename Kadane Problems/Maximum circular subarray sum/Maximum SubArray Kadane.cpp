#include<iostream>
#include<climits>
#include<vector>
using namespace std;

int kadane(int *nums, int n)
{
    int max_sum = INT_MIN;
    int curr_sum = 0;
    for(int i = 0; i< n; i++)
    {
        curr_sum = curr_sum + nums[i];
        if(max_sum < curr_sum)
        {
            max_sum = curr_sum;
        }

        if(curr_sum < 0)
        {
            curr_sum = 0;
        }
    }
    return max_sum;
}

int maxCircularSum(int a[], int n)
{
    // Case 1: get the maximum sum using standard kadane's algorithm
    int max_kadane = kadane(a, n);
     // if maximum sum using standard kadane' is less than 0
    if(max_kadane < 0)
    {
      return max_kadane;
    }

    // Case 2: Now find the maximum sum that includes
    // corner elements.
    int max_wrap = 0, i;
    for (i = 0; i < n; i++)
    {
        max_wrap += a[i]; // Calculate array-sum
        a[i] = -a[i]; // invert the array (change sign)
    }

    // max sum with corner elements will be:
    // array-sum - (-max subarray sum of inverted array)
    max_wrap = max_wrap + kadane(a, n);

    // The maximum circular sum will be maximum of two sums
    return (max_wrap > max_kadane) ? max_wrap : max_kadane;
}

int main()
{
    int arr[] = { 11, 10, -20, 5, -3, -5, 8, -13, 10 };
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<maxCircularSum(arr, n);
    return 0;
}
