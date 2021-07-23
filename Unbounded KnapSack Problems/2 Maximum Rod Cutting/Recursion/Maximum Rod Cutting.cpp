#include<iostream>
using namespace std;

int solve(int *price, int *length, int max_len, int n)
{
    if(max_len==0||n==0)
    {
        return 0;
    }

    int ans;
    if(length[n-1]<=max_len)
    {
        int a = price[n-1] + solve(price,length, max_len-length[n-1], n);
        int b = solve(price,length, max_len, n-1);
        ans = max(a,b);
    }
    else
    {
        ans = solve(price,length, max_len, n-1);
    }
    return ans;
}


int main()
{
    int price[] = { 1, 5, 8, 9, 10, 17, 17, 20 };
    int n = 8;
    int *length = new int [n];
    for (int i = 0; i < n; i++)
    {
        length[i] = i + 1;
    }
    int max_len = n;
    cout<<solve(price, length, max_len, n);
}
