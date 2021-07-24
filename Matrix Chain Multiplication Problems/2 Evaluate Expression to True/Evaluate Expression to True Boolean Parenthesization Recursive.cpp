#include<iostream>
#include<climits>
#include<vector>
#include<unordered_map>
#include<cstring>
using namespace std;


// brute force
int expression(string str, int i, int j, bool isTrue)
{
    if( i > j )
    {
      return false;
    }

    if(i==j)
    {
        if(isTrue==true)
        {
            return str[i] == 'T';
        }
        else
        {
            return str[i] == 'F';
        }
    }

    int ans = 0;
    for(int k = i+1; k < j; k = k + 2)
    {
      int leftT = expression(str, i, k-1, true);
      int leftF = expression(str, i, k-1, false);
      int rightT = expression(str, k + 1, j, true);
      int rightF = expression(str, k + 1, j, false);
      int case1 = leftT * rightT;
      int case2 = leftF * rightT;
      int case3 = leftT * rightF;
      int case4 = leftF * rightF;
      if(str[k]== '&')
      {
          if(isTrue == true)
          {
              ans = ans + case1;
          }
          else
          {
              ans = ans +  case2 + case3 +  case4;
          }
      }
      else if(str[k]== '|')
      {
          if(isTrue == true)
          {
              ans = ans +  case1 + case2 +  case3;
          }
          else
          {
              ans = ans +  case4;
          }
      }
      else if(str[k]== '^')
      {
          if(isTrue == true)
          {
               ans = ans +  case2 + case3;
          }
          else
          {
              ans = ans +  case1 + case4;
          }
      }
    }
    return ans;
}


//memoization
int solveExpression(string str, int i, int j, bool isTrue, unordered_map<string, int> ans)
{
    if( i > j )
    {
      return false;
    }

    if(i==j)
    {
        if(isTrue==true)
        {
            return str[i] == 'T';
        }
        else
        {
            return str[i] == 'F';
        }
    }

    string temp = to_string(i);
    temp.push_back(' ');
    temp.append(to_string(j));
    temp.push_back(' ');
    temp.append(to_string(isTrue));

    if(ans.find(temp)!=ans.end())
    {
        return ans[temp];
    }


    int result = 0;
    for(int k = i+1; k < j; k = k + 2)
    {
      int leftT  = solveExpression(str, i, k-1, true, ans);
      int leftF  = solveExpression(str, i, k-1, false, ans);
      int rightT = solveExpression(str, k + 1, j, true, ans);
      int rightF = solveExpression(str, k + 1, j, false, ans);
      int case1 = leftT * rightT;
      int case2 = leftF * rightT;
      int case3 = leftT * rightF;
      int case4 = leftF * rightF;
      if(str[k]== '&')
      {
          if(isTrue == true)
          {
              result = result + case1;
          }
          else
          {
              result = result +  case2 + case3 +  case4;
          }
      }
      else if(str[k]== '|')
      {
          if(isTrue == true)
          {
              result = result +  case1 + case2 +  case3;
          }
          else
          {
              result = result +  case4;
          }
      }
      else if(str[k]== '^')
      {
          if(isTrue == true)
          {
               result = result +  case2 + case3;
          }
          else
          {
              result = result +  case1 + case4;
          }
      }
    }

    ans[temp] = result;
    return result;
}


int solveExpression(string str)
{
    int n = str.size();
    unordered_map<string, int> ans;
    ans.clear();
    return solveExpression(str,0, n-1, true, ans);
}



int main()
{
    string symbols = "TTFT";
    string operators = "|&^";
    string s;
    int j = 0;

    for (int i = 0; i < symbols.length(); i++)
    {
        s.push_back(symbols[i]);
        if (j < operators.length())
            s.push_back(operators[j++]);
    }

    // We obtain the string  T|T&F^T
    int n = s.length();

    // There are 4 ways
    // ((T|T)&(F^T)), (T|(T&(F^T))), (((T|T)&F)^T) and
    // (T|((T&F)^T))
    //memset(dp, -1, sizeof(dp));
    cout << solveExpression(s);
    return 0;
}
