#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int maxEnvelopes(vector<vector<int>> &arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    for (vector<int> vect1D : arr)
    {
        for (int x : vect1D)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    int *ans = new int[n];
    ans[0] = 1;
    int mx = ans[0];
    for(int i=1;i<n;++i)
    {
        ans[i] = 1;
        for(int j=0;j<i;++j)
        {
            if(arr[j][0] < arr[i][0] && arr[j][1] < arr[i][1] && ans[i] < ans[j] +1)
            {
                ans[i] = ans[j] + 1;
            }
        }
        mx = max(mx, ans[i]);
    }
    return mx;
}

int main()
{
    vector<vector<int>> arr
    {
        {5,4},
        {6,4},
        {6,7},
        {2,3}
    };
    cout<<maxEnvelopes(arr);
}

