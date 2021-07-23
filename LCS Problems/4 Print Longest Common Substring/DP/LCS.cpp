#include<vector>
#include<climits>
#include<iostream>
#include<algorithm>
using namespace std;

class dims
{
    public:
        int row, col;
};

//DP Method
dims lcs(string str1, string str2, int m, int n, int **ans)
{
    dims d;
    int result = INT_MIN;
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
                if(result < ans[i][j])
                {
                    result = ans[i][j];
                    d.row = i;
                    d.col = j;
                }
            }
            else
            {
                ans[i][j] = 0;
            }
        }
    }
    return d;
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

    dims d = lcs(str1, str2, m, n, ans);
    int row = d.row, col = d.col;
    vector<char> output;
    while(ans[row][col]!=0)
    {
        output.push_back(str1[row-1]);
        row--; col--;
    }

    reverse(output.begin(), output.end());

    for(auto ch:output)
    {
        cout<<ch;
    }

}

int main()
{
    lcs("GeeksforGeeks", "GeeksQuiz");
    cout<<"\n\n";
    lcs("zxabcdezy", "yzabcdezx");
    cout<<"\n\n";
}
