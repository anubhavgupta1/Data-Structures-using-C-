#include<iostream>
#include<climits>
#include<vector>
using namespace std;

int maxSubArraySum(int *nums, int n)
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

int main()
{
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<maxSubArraySum(arr, n);
    return 0;
}
