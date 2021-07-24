#include<iostream>
using namespace std;


int lis(int *arr, int n)
{
    int *op = new int[n];
    op[0] = 1;
    int mx = 1;
    for(int i =1; i<n; i++)
    {
        op[i] = 1;
        for(int j = 0; j<i; j++)
        {
            if(arr[j]<arr[i] && op[i] < op[j] + 1)
            {
                op[i] = op[j] + 1;
            }
        }
        mx = max(mx, op[i]);
    }
    return mx;
}

int main()
{
    int arr[] = {5, 4, 11, 1, 16, 8};
    cout<<lis(arr,6);
}
