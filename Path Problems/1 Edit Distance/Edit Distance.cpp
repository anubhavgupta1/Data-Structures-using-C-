#include<iostream>
using namespace std;

int editDistance(string str1, string str2, int m, int n)
{
    if(m==0)
    {
        return n;
    }
    else if(n==0)
    {
        return m;
    }

    int ans;
    if(str1[m-1]==str2[n-1])
    {
        ans = editDistance(str1, str2, m-1, n-1);
    }
    else
    {
        int ans1 = 1 + editDistance(str1, str2, m-1, n);
        int ans2 = 1 + editDistance(str1, str2, m, n-1);
        int ans3 = 1 + editDistance(str1, str2, m-1, n-1);
        ans = min(ans1, min(ans2, ans3));
    }
    return ans;
}

int editDistance(string str1, string str2, int m, int n, int **dp)
{
    if(m==0)
    {
        return n;
    }
    else if(n==0)
    {
        return m;
    }

    if(dp[m][n]!=-1)
    {
        return dp[m][n];
    }

    int ans;
    if(str1[m-1]==str2[n-1])
    {
        ans = editDistance(str1, str2, m-1, n-1, dp);
    }
    else
    {
        int ans1 = 1 + editDistance(str1, str2, m-1, n, dp);
        int ans2 = 1 + editDistance(str1, str2, m, n-1, dp);
        int ans3 = 1 + editDistance(str1, str2, m-1, n-1, dp);
        ans = min(ans1, min(ans2, ans3));
    }

    dp[m][n] = ans;
    return ans;
}


int editDistanceDP(string str1, string str2, int m, int n)
{
    int **ans = new int* [m+1];
    for(int i = 0; i<m+1; i++)
    {
        ans[i] = new int[n+1];
    }

    for(int i = 0; i<m+1; i++)
    {
        ans[i][0] = i;
    }

    for(int i = 0; i<n+1; i++)
    {
        ans[0][i] = i;
    }


    for(int i = 1; i<m+1; i++)
    {
        for(int j = 1; j<n+1; j++)
        {
            if(str1[i]==str2[j])
            {
                ans[i][j] = ans[i-1][j-1];
            }
            else
            {
                int a = 1 + ans[i-1][j-1];
                int b = 1 + ans[i-1][j];
                int c = 1 + ans[i][j-1];
                ans[i][j] = min(a, min(b,c));
            }
        }
    }

    return ans[m][n];

}


void editDistance(string str1, string str2)
{
    int m = str1.size();
    int n = str2.size();
    int **ans = new int* [m+1];
    for(int i = 0; i<m+1; i++)
    {
        ans[i] = new int[n+1];
    }

    for(int i = 0; i<m+1; i++)
    {
        for(int j = 0; j<n+1; j++)
        {
            ans[i][j] = -1;
        }
    }

    cout<<"Recursive : "<<editDistance(str1, str2, str1.size(), str2.size())<<"\n";
    cout<<"Memoization : "<<editDistance(str1, str2, str1.size(), str2.size(), ans)<<"\n";
    cout<<"DP : "<<editDistanceDP(str1, str2, m, n);
}


int main()
{
    editDistance("sunday", "saturday");
}
