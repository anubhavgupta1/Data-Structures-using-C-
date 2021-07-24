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
        ans = lcs(str1, str2, m-1, n);
    }
    return ans;
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
