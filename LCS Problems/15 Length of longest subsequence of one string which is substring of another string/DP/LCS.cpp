#include<iostream>
#include<cstring>
using namespace std;

int maxSubsequenceSubstring(string str1, string str2, int m, int n)
{
    int dp[10][10];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            dp[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (str1[j - 1] == str2[i - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = dp[i][j - 1];
            }

        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, dp[i][m]);
    }
    return ans;
}

int main()
{
    string str1 = "abcd";
    string str2 = "bacdbdcd";
    cout<<maxSubsequenceSubstring(str1, str2,4,8);
}
