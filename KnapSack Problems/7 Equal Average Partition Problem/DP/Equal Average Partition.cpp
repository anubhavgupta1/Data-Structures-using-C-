#include<iostream>
#include <vector>
#include <algorithm>
#include<string>
#include<unordered_map>
using namespace std;

// recursive brute force
bool check(vector<int> &arr, int i, int sum, int count,vector<int> &result)
{
    if(count==0)
    {
        return sum==0;
    }
    if(arr.size()<=i)
    {
        return false;
    }
    bool ans;
    if(arr[i]<=sum)
    {
        result.push_back(arr[i]);
        ans  = check(arr, i +1, sum - arr[i],count - 1, result);
        if(ans==true)
        {
            return true;
        }
        result.pop_back();

    }
    ans = check(arr, i +1, sum,count, result);
    return ans;
}

// memoization
bool check(vector<int> &arr, int i, int sum, int count,vector<int> &result, unordered_map<string, bool> dp)
{
    if(count==0)
    {
        return sum==0;
    }
    if(arr.size()<=i)
    {
        return false;
    }

    string key = to_string(i);
    key.push_back(' ');
    key.append(to_string(sum));
    key.push_back(' ');
    key.append(to_string(count));

    if(dp.find(key)!=dp.end())
    {
        return dp[key];
    }

    bool ans;
    if(arr[i]<=sum)
    {
        result.push_back(arr[i]);

        string key1 = to_string(i+1);
        key1.push_back(' ');
        key1.append(to_string(sum - arr[i]));
        key1.push_back(' ');
        key1.append(to_string(count - 1));
        if(dp.find(key1)!=dp.end())
        {
            ans =  dp[key1];
        }
        else
        {
            ans  = check(arr, i +1, sum - arr[i],count - 1, result,dp);
        }

        if(ans==true)
        {
            dp[key1] = true;
            return true;
        }
        result.pop_back();

    }
    string key2 = to_string(i+1);
    key2.push_back(' ');
    key2.append(to_string(sum));
    key2.push_back(' ');
    key2.append(to_string(count));
    if(dp.find(key2)!=dp.end())
    {
        ans =  dp[key2];
    }
    else
    {
        ans = check(arr, i +1, sum,count, result,dp);
    }

    dp[key] = ans;
    return ans;
}


void splitArraySameAverage (vector<int>& arr)
{
    unordered_map<string, bool> dp;
    dp.clear();
    int sum = 0;
    int n = arr.size();
    for(auto it : arr)
    {
        sum = sum + it;
    }

    for(int i = 1; i<n; i++)
    {
        if(sum*i % n == 0)
        {
            int check_sum = (sum * i) / n;
            vector<int> result;
            bool ifPossible = check(arr, 0, check_sum, i,result, dp);
            if(ifPossible==true)
            {
                for(auto it : result)
                {
                    cout<<it<<" ";
                }
                cout<<"\n";
                sort(arr.begin(),arr.end());
                sort(result.begin(),result.end());
                vector<int> diff;
                set_difference(arr.begin(), arr.end(), result.begin(), result.end(), inserter(diff, diff.begin() ) );
                for(auto it : diff)
                {
                    cout<<it<<" ";
                }
                break;
            }
        }
    }
}

int main()
{
    vector<int> arr  = {1, 2, 3, 4, 5, 6};
    splitArraySameAverage (arr);
    cout<<"\n\n";
    return 0;
}
