#include<iostream>
#include<unordered_map>
using namespace std;

unordered_map<string,bool> umap;

bool check(string s1, string s2, string s3, int len1, int len2, int len3, int p1, int p2, int p3)
{
    string key = to_string(p1) + " " + to_string(p2) + " " + to_string(p3);
    if(umap.find(key)!=umap.end())
    {
        return umap[key];
    }

    //base case
    if(len3==p3)
    {
        return (len1==p1 && len2==p2);
    }

    //case1 : s1 is passed
    if(len1==p1)
    {
        if(s2[p2]==s3[p3])
        {
            return umap[key] = check(s1, s2, s3, len1, len2, len3, p1, p2+1, p3+1);
        }
        else
        {
            return umap[key] = false;
        }
    }

    //case2 : s2 is passed
    if(len2==p2)
    {
        if(s1[p1]==s3[p3])
        {
            return umap[key] = check(s1, s2, s3, len1, len2, len3, p1+1, p2, p3+1);
        }
        else
        {
                return umap[key] = false;
        }
    }

    //case3 : neither s1 nor s2 is passed
    bool check1 = false, check2 = false;
    if(s1[p1]==s3[p3])
    {
        check1 = check(s1, s2, s3, len1, len2, len3, p1+1, p2, p3+1);
    }

    if(s2[p2]==s3[p3])
    {
        check2 = check(s1, s2, s3, len1, len2, len3, p1, p2+1, p3+1);
    }

    return umap[key] = check1 || check2;

}

bool isInterleave(string s1, string s2, string s3)
{
    int m = s1.size();
    int n = s2.size();
    int p = s3.size();
    return check(s1, s2, s3, m, n, p, 0, 0, 0);
}

int main()
{
    cout<<isInterleave("aabcc", "dbbca", "aadbbcbcac");cout<<"\n";
}
