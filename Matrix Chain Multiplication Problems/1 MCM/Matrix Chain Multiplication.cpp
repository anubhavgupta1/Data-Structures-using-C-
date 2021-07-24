#include<iostream>
#include<climits>
using namespace std;

//Brute force

int solve(int *arr, int i, int j)
{
    cout<<i<<" "<<j<<"\n";
    if(i>=j)
    {
        return 0;
    }

    int minimum = INT_MAX;
    for( int k = i; k<j; k++) // k : 1 to j-1
    {
        int ans1 = solve(arr, i, k);
        int ans2 = solve(arr, k+1, j);
        int ans3 = arr[i-1] * arr[k] * arr[j];
        int ans = ans1 + ans2 + ans3;
        minimum = min(minimum, ans);
    }
    return minimum;
}

//
int solveMem(int *arr, int i, int j, int **ans)
{
    if(i>=j)
    {
        return 0;
    }

    if(ans[i][j]!=-1)
    {
        return ans[i][j];
    }

    int minimum = INT_MAX;
    for( int k = i; k<j; k++) // k : 1 to j-1
    {
        int ans1 = solveMem(arr, i, k+1, ans);
        int ans2 = solveMem(arr, k+2, j, ans);
        int ans3 = arr[i-1] * arr[k] * arr[j];
        int ans4 = ans1 + ans2 + ans3;
        minimum = min(minimum, ans4);
    }

    ans[i][j] = minimum;
    return minimum;
}

void solve(int *arr, int n)
{
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
    int a = solveMem(arr, 1, n-1, ans);
    int b = solve(arr, 1, n-1);
    cout<<"Brute force : "<<b;
    cout<<"\n\nMemoization : "<<a;
}

int main()
{
    int arr[] = {10, 20, 30, 40, 30};
    solve(arr, 5);
    cout<<"\n\n";
}
