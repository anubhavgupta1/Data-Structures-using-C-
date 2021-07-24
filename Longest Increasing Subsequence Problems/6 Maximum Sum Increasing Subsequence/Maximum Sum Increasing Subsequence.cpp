#include<iostream>
using namespace std;


int maxSumIS(int *arr, int n)
{
    int *op = new int[n];
    op[0] = arr[0];
    int mx = arr[0];
    for(int i =1; i<n; i++)
    {
        op[i] = arr[i];
        for(int j = 0; j<i; j++)
        {
            if(arr[j]<arr[i] && op[i] < op[j] + arr[i])
            {
                op[i] = op[j] + arr[i];
            }
        }
        mx = max(mx, op[i]);
    }
    return mx;
}

int main()
{
    int arr[] = {1, 101, 2, 3, 100, 4, 5};
    cout<<maxSumIS(arr,7);
}
