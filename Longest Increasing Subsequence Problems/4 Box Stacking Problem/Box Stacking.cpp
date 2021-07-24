#include<iostream>
#include<algorithm>
using namespace std;

class Box
{
    public:
    int h, w, l;
};


bool compare (Box a, Box b)
{
    return ( a.l * a.w ) > (b.l * b.w);
}

int maxStackHeight1(Box arr[], int n )
{
    int *msh = new int[n];
    msh[0] = arr[0].h;
    int maxa = msh[0];
    cout<<msh[0]<<" "<<arr[0].l<<" "<<arr[0].w<<"\n";
    for (int i = 1; i < n; i++ )
    {
        msh[i] = arr[i].h;
        for (int j = 0; j < i; j++ )
        {
            if(arr[i].w < arr[j].w && arr[i].l < arr[j].l && msh[i] < msh[j] + arr[i].h)
            {
                msh[i] = msh[j] + arr[i].h;
            }
        }
        maxa = max(maxa, msh[i]);
    }

   return maxa;
}


int maxStackHeight( Box arr[], int n )
{
   Box *rot = new Box[3*n];
   int index = 0;
   for (int i = 0; i < n; i++)
   {
      // Copy the original box
      rot[index].h = arr[i].h;
      rot[index].l = max(arr[i].l, arr[i].w);
      rot[index].w = min(arr[i].l, arr[i].w);
      index++;

      // First rotation of box
      rot[index].h = arr[i].w;
      rot[index].l = max(arr[i].h, arr[i].l);
      rot[index].w = min(arr[i].h, arr[i].l);
      index++;

      // Second rotation of box
      rot[index].h = arr[i].l;
      rot[index].l = max(arr[i].h, arr[i].w);
      rot[index].w = min(arr[i].h, arr[i].w);
      index++;
   }

   n = 3*n;

   sort (rot, rot+n, compare);
   return maxStackHeight1(rot, n);
}

/* Driver program to test above function */
int main()
{
  Box arr[] = { {4, 6, 7}, {1, 2, 3}, {4, 5, 6}, {10, 12, 32} };
  cout<<maxStackHeight(arr, 4);
  return 0;
}
