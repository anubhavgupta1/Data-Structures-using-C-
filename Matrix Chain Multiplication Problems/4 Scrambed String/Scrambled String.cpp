#include<iostream>
#include<cstring>
#include<unordered_map>
using namespace std;

bool isScrumbled(string str1, string str2)
{
    if (str1.length() != str2.length())
    {
        return false;
    }

    int n = str1.length();

    if(str1==str2 || n==0)
    {
        return true;
    }

    for(int i= 1; i<n; i++)
    {
        bool subCon1 = isScrumbled(str1.substr(0, i), str2.substr(n-i, i)) == true ;
        bool subCon2 = isScrumbled(str1.substr(i, n-i), str2.substr(0, n-i)) == true ;
        bool subCon3 = isScrumbled(str1.substr(0, i), str2.substr(0, i)) == true ;
        bool subCon4 = isScrumbled(str1.substr(i, n-i), str2.substr(i, n-i)) == true ;
        bool con1 = subCon1 && subCon2;
        bool con2 = subCon3 && subCon4;
        if(con1 || con2)
        {
            return true;
        }
    }
    return false;
}

//memoization
bool isScrumbled(string str1, string str2, unordered_map<string, bool> ans)
{
    if (str1.length() != str2.length())
    {
        return false;
    }

    int n = str1.length();

    if(str1==str2 || n==0)
    {
        return true;
    }

    string key = str1;
    key.push_back(' ');
    key.append(str2);

    if(ans.find(key)!=ans.end())
    {
        return ans[key];
    }

    bool flag = false;

    for(int i= 1; i<n; i++)
    {
        bool subCon1 = isScrumbled(str1.substr(0, i), str2.substr(n-i, i), ans) == true ;
        bool subCon2 = isScrumbled(str1.substr(i, n-i), str2.substr(0, n-i), ans) == true ;
        bool subCon3 = isScrumbled(str1.substr(0, i), str2.substr(0, i), ans) == true ;
        bool subCon4 = isScrumbled(str1.substr(i, n-i), str2.substr(i, n-i), ans) == true ;
        bool con1 = subCon1 && subCon2;
        bool con2 = subCon3 && subCon4;
        if(con1 || con2)
        {
            flag = true;
            break;
        }
    }
    ans[key] = flag;
    return flag;
}

bool helper(string str1, string str2)
{
    unordered_map<string, bool> ans;
    return isScrumbled(str1, str2, ans);
}

int main()
{
    string str1 = "coder";
    string str2 = "ocder";
    cout<<isScrumbled(str1,str2);
    cout<<helper(str1,str2);
}
