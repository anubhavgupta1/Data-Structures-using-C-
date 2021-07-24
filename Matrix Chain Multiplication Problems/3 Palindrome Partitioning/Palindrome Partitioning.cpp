#include<iostream>
#include<climits>
using namespace std;

bool isPalindrome(string str, int i, int j)
{
    while(i < j)
    {
      if(str[i] != str[j])
      {
         return false;
      }

      i++;
      j--;
    }
    return true;
}

int minPalPartion(string str, int i, int j)
{
    if( i >= j || isPalindrome(str, i, j) )
    {
      return 0;
    }

    int minimum = INT_MAX;
    for(int k = i; k < j; k++)
    {
      int ans1 = minPalPartion(str, i, k);
      int ans2 = minPalPartion(str, k + 1, j);
      int ans = ans1 + ans2 + 1;
      minimum = min(minimum, ans);
    }
    return minimum;
}


int solve(string str, int i, int j, int **ans)
{
    if( i >= j || isPalindrome(str, i, j) )
    {
      return 0;
    }

    if(ans[i][j]!=-1)
    {
        return ans[i][j];
    }

    int minimum = INT_MAX;
    for(int k = i; k < j; k++)
    {
      int ans1 = solve(str, i, k, ans);
      int ans2 = solve(str, k + 1, j, ans);
      int ans3 = ans1 + ans2 + 1;
      minimum = min(minimum, ans3);
    }

    ans[i][j] = minimum;
    return minimum;
}

int solve1(string str, int i, int j, int **ans)
{
    if( i >= j || isPalindrome(str, i, j) )
    {
      return 0;
    }

    if(ans[i][j]!=-1)
    {
        return ans[i][j];
    }

    int minimum = INT_MAX;
    for(int k = i; k < j; k++)
    {
          int ans1, ans2;
          if(ans[i][k]!=-1)
          {
              ans1 = ans[i][k];
          }
          else
          {
              ans1 = solve1(str, i, k, ans);
          }

          if(ans[k+1][j]!=-1)
          {
              ans2 = ans[k+1][j];
          }
          else
          {
              ans2 = solve1(str, i, k, ans);
          }

          int ans3 = ans1 + ans2 + 1;
          minimum = min(minimum, ans3);
    }

    ans[i][j] = minimum;
    return minimum;
}


void solve(string str)
{
    int n = str.size();
    int **ans;
    ans = new int* [n];
    for(int i = 0; i<n;i ++)
    {
        ans[i] = new int [n];
    }
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            ans[i][j] = -1;
        }
    }

    int a = minPalPartion(str, 0, n-1);
    cout<<"Brute force : "<<a;
    int b = solve(str, 0, n-1, ans);
    cout<<"\n\nMemoization : "<<b;
    int c = solve1(str, 0, n-1, ans);
    cout<<"\n\nMemoization Optimized : "<<c;
}

int main()
{
    solve("geek");
    cout<<"\n\n";
}
