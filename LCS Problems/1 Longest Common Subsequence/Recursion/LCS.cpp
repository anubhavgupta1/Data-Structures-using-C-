#include<iostream>
using namespace std;

int lcs(string str1, string str2, int m, int n)
{
    if(m==0 ||n==0)
    {
        return 0;
    }
    int ans;
    if(str1[m-1]==str2[n-1])
    {
        ans = 1 + lcs(str1, str2, m-1, n-1);
    }
    else
    {
        int a = lcs(str1, str2, m, n-1);
        int b = lcs(str1, str2, m-1, n);
        ans = max(a,b);
    }
    return ans;
}


int main()
{
    cout<<lcs("abcdgh","abedfha", 6, 7);
}
