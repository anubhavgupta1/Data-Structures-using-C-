#include<iostream>
#include<cstring>
#include<climits>
#include<unordered_map>
using namespace std;

int eggDrop1(int eggs, int floors)
{
    if(eggs==1 || floors == 0 || floors == 1)
    {
        return floors;
    }

    int minimum = INT_MAX;
    for(int k = 1; k <=floors; k++)
    {
        int ans1 = eggDrop1(eggs-1, k-1);
        int ans2 = eggDrop1(eggs, floors - k);
        int ans3 = 1 + max(ans1, ans2);
        minimum = min(minimum, ans3);
    }
    return minimum;
}



int eggDrop(int eggs, int floors, int **ans)
{
    if(eggs==1 || floors == 0 || floors == 1)
    {
        return floors;
    }

    if(ans[eggs][floors]!=-1)
    {
        return ans[eggs][floors];
    }

    int minimum = INT_MAX;
    for(int k = 1; k <=floors; k++)
    {
        int ans1 = eggDrop(eggs-1, k-1, ans);
        int ans2 = eggDrop(eggs, floors - k, ans);
        int ans3 = 1 + max(ans1, ans2);
        minimum = min(minimum, ans3);
    }

    ans[eggs][floors] = minimum;
    return minimum;
}


int eggDrop2(int eggs, int floors, int **ans)
{
    if(eggs==1 || floors == 0 || floors == 1)
    {
        return floors;
    }

    if(ans[eggs][floors]!=-1)
    {
        return ans[eggs][floors];
    }

    int minimum = INT_MAX;
    for(int k = 1; k <=floors; k++)
    {
        int ans1, ans2;
        if(ans[eggs-1][k-1]!=-1)
        {
           ans1 = ans[eggs-1][k-1];
        }
        else
        {
            ans1 = eggDrop2(eggs-1, k-1, ans);
        }

        if(ans[eggs][floors-k]!=-1)
        {
           ans2 = ans[eggs][floors-k];
        }
        else
        {
            ans2 = eggDrop2(eggs, floors - k, ans);
        }

        int ans3 = 1 + max(ans1, ans2);
        minimum = min(minimum, ans3);
    }

    ans[eggs][floors] = minimum;
    return minimum;
}


void eggDrop(int eggs, int floors)
{
    int **ans =  new int* [eggs+1];
    for(int i =0; i<eggs+1; i++)
    {
        ans[i] = new int [floors+1];
    }
    for(int i =0; i<eggs+1; i++)
    {
        for(int j =0; j<floors+1; j++)
        {
            ans[i][j] = -1;
        }
    }
    cout<<eggDrop(eggs, floors, ans);
    cout<<eggDrop2(eggs, floors, ans);
}

int main()
{
    cout<<eggDrop1(2,10)<<"\n";
    //cout<<eggDrop1(2,36)<<"\n\n";
    eggDrop(2,10);
    eggDrop(2,36);
}
