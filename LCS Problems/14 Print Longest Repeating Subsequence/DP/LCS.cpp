#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

//DP Method
void lcs(string str1, string str2, int m, int n, int **ans)
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
            if(str1[i-1]==str2[j-1] && i!=j)
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
}

void lcs(string str1, string str2)
{
    int m = str1.size();
    int n = str2.size();
    int **ans;
    ans = new int* [m+1];
    for(int i = 0; i< m+1; i++)
    {
        ans[i] = new int[n+1];
    }

    lcs(str1, str2, m, n, ans);
    int i = m, j = n;
    string res = "";
    while(i>0 && j>0)
    {
        if (ans[i][j] == ans[i-1][j-1] + 1)
        {
           res = res + str1[i-1];
           i--;
           j--;
        }
        else
        {
            if(ans[i][j] == ans[i-1][j])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
    }

    reverse(res.begin(), res.end());
    cout<<res;

}

int main()
{
    lcs("aabebcdd", "aabebcdd");
    cout<<"\n\n";
}
