#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void PrintLIS(int *arr, int *lis , int n)
{
    vector<int> output;
    int maxi_index = 0;
    int maxi = lis[maxi_index];
    for(int i = n-1; 0<=i; i--)
    {
        if(maxi < lis[i])
        {
            maxi_index = i;
            maxi = lis[i];
        }
    }
    output.push_back(arr[maxi_index]);
    for(int i = maxi_index-1; 0<=i; i--)
    {
        if(lis[i] + 1 == lis[maxi_index] && arr[i] < arr[maxi_index] )
        {
            maxi_index = i;
            output.push_back(arr[maxi_index]);
        }
    }
    reverse(output.begin(), output.end());
    cout<<"Longest Increasing subsequence is : ";
    for(auto it : output)
    {
        cout<<it<<" ";
    }
    cout<<"\n\n";
    cout<<"Length of Longest Increasing subsequence is : ";
}


int lis(int *arr, int n)
{
    int *lis = new int [n];

    lis[0] = 1;

    for(int i = 1 ; i <n; i++)
    {
        lis[i] = 1;
        for(int j = 0 ; j <i; j++)
        {
            if(arr[j] < arr[i] && lis[i]<lis[j]+1)
            {
                lis[i] = lis[j] + 1;
            }
        }
    }
    PrintLIS(arr, lis, n);
    return *max_element(lis, lis+n);
}




int main()
{
    int arr[] = { 50, 3, 10, 7, 40, 80};
    cout<<lis(arr,6);
    cout<<"\n\n";
}
