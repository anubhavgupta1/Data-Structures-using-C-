//Minimum Operations to Reduce X to Zero
#include<unordered_map>
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int solve(vector<int>& arr, int sum, int left, int right, int count)
{

    if(sum==0)
    {
        return count;
    }

    if(sum<0 || right<left)
    {
        return INT_MAX;
    }
    int l = solve(arr, sum-arr[left], left+1, right, count+1);
    int r = solve(arr, sum-arr[right], left, right-1, count+1);
    return min(l,r);
}

int main()
{
    vector<int> arr{1,1,4,2,3};
    int ans = solve(arr, 5, 0, arr.size()-1, 0);
    cout<<ans;
}
