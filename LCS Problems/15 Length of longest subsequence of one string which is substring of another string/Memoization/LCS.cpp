#include<iostream>
using namespace std;

//Memoization Method
int lcs(string str1, string str2, int m, int n, int **ans)
{
    if(m==0 || n==0)
    {
        return 0;
    }

    if(ans[m][n]!=-1)
    {
        return ans[m][n];
    }

    if(str1[m-1]==str2[n-1])
    {
        ans[m][n] = 1 + lcs(str1, str2, m-1, n-1, ans);
    }
    else
    {
        ans[m][n] = lcs(str1, str2, m-1, n, ans);
    }

    return  ans[m][n];
}


int lcs(string str1, string str2, int m, int n)
{
    int **ans;
    ans = new int* [m+1];
    for(int i = 0; i< m+1; i++)
    {
        ans[i] = new int[n+1];
    }
    for(int i = 0; i < m+1; i++)
    {
        for(int j = 0; j<n+1; j++)
        {
            ans[i][j] = -1;
        }
    }
    return lcs(str1, str2, m, n, ans);
}


int main()
{
    string str1 = "abcd";
    string str2 = "bacdbdcd";
    int max_len = 0;
    for(int i = 0; i< str2.size(); i++)
    {
        int temp = lcs(str1,str2, 4, i);
        max_len = max(max_len, temp);
    }
    cout<<max_len;
}
