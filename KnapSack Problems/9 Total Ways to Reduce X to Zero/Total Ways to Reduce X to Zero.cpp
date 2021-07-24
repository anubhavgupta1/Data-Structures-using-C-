//Minimum Operations to Reduce X to Zero
#include<unordered_map>
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int solve(vector<int>& arr, int sum, int left, int right)
{

    if(sum==0)
    {
        return 1;
    }

    if(sum<0 || right<left)
    {
        return 0;
    }
    int l = solve(arr, sum-arr[left], left+1, right);
    int r = solve(arr, sum-arr[right], left, right-1);
    return l+r;
}

int main()
{
    vector<int> arr{1,1,4,2,3};
    int ans = solve(arr, 5, 0, arr.size()-1);
    cout<<ans;
}
