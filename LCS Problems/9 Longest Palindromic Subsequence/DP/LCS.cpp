#include<iostream>
#include<algorithm>
using namespace std;

//DP Method
int lcs(string str1, string str2, int m, int n, int **ans)
{
    for(int i = 0; i< m+1; i++)
    {
        ans[i][0] = 0;
    }

    for(int i = 0; i< n+1; i++)
    {
        ans[0][i] = 0;
    }

    for(int i = 1; i < m+1; i++)
    {
        for(int j = 1; j<n+1; j++)
        {
            if(str1[i-1]==str2[j-1])
            {
                ans[i][j] = 1 + ans[i-1][j-1];
            }
            else
            {
                int a = ans[i][j-1];
                int b = ans[i-1][j];
                ans[i][j] = max(a,b);
            }
        }
    }

    return  ans[m][n];
}

int lcs(string str1)
{
    int m = str1.size();
    int **ans;
    ans = new int* [m+1];
    for(int i = 0; i< m+1; i++)
    {
        ans[i] = new int[m+1];
    }
    string str2 = str1;
    reverse(str2.begin(), str2.end());
    return lcs(str1, str2, m, m, ans);
}

int main()
{
    cout<<lcs("agbcba");
}
