#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int lis(int *arr, int n)
{

    vector<int> output;
    output.push_back(arr[0]);
    int *lis = new int [n];

    for(int i = 1 ; i <n; i++)
    {
        if(output.back()<arr[i])
        {
            output.push_back(arr[i]);
        }
        else
        {
            //Iterator lower_bound (Iterator first, Iterator last, const val)
            //Iterator upper_bound (Iterator first, Iterator last, const val)
            //lower_bound returns an iterator pointing to the first element
            //in the range [first,last) which has a value not less than ‘val’.
            //upper_bound returns an iterator pointing to the first element
            //in the range [first,last) which has a value greater than ‘val’.
            // complexity of the approach is O(logN)
            auto it2 = output.begin();
            auto it1 = lower_bound(output.begin(), output.end(), arr[i]);
            cout<<*it1<<" - "<<*it2<<"\n";
            int key = lower_bound(output.begin(), output.end(), arr[i]) - output.begin();
            output[key] = arr[i];
        }
    }
    for(auto it : output)
    {
        cout<<it<<" ";
    }
    cout<<"\n";
    return output.size();
}




int main()
{
    int arr[] = { 50, 3, 10, 7, 40, 80};
    cout<<lis(arr,6);
    cout<<"\n\n";
}
