#include<iostream>
#include<vector>
using namespace std;

int uniquePathsWithObstacles1(vector<vector<int>>& arr)
{

    int r = arr.size(), c = arr[0].size();

    // create a 2D-matrix and initializing with value 0
    vector<vector<int>> paths(r, vector<int>(c, 0));

    // Initializing the left corner if no obstacle there
    if (arr[0][0] == 0)
    {
        paths[0][0] = 1;
    }

    // Initializing first column of the 2D matrix
    for(int i = 1; i < r; i++)
    {
        // If not obstacle
        if (arr[i][0] == 0)
        {
            paths[i][0] = paths[i-1][0];
        }

    }

    // Initializing first row of the 2D matrix
    for(int j = 1; j < c; j++)
    {

        // If not obstacle
        if (arr[0][j] == 0)
        {
            paths[0][j] = paths[0][j - 1];
        }

    }

    for(int i = 1; i < r; i++)
    {
        for(int j = 1; j < c; j++)
        {
            // If current cell is not obstacle
            if (arr[i][j] == 0)
            {
                paths[i][j] = paths[i - 1][j] + paths[i][j - 1];
            }

        }
    }

    // Returning the corner value of the matrix
    return paths[r - 1][c-1];
}

int uniquePathsWithObstacles2(vector<vector<int> >& arr)
{

    int r = arr.size();
    int c = arr[0].size();

    // If obstacle is at starting position
    if (arr[0][0] == 1)
    {
        return 0;
    }

    //  Initializing starting position
    arr[0][0] = 1;

    // first row all are '1' until obstacle
    for (int j = 1; j < c; j++)
    {
        if (arr[0][j] == 0)
        {
            arr[0][j] = arr[0][j - 1];
        }
        else
        {
            // No ways to reach at this index
            arr[0][j] = 0;
        }
    }

    // first column all are '1' until obstacle
    for (int i = 1; i < r; i++)
    {

        if (arr[i][0] == 0)
        {
            arr[i][0] = arr[i - 1][0];
        }
        else
        {
            // No ways to reach at this index
            arr[i][0] = 0;
        }
    }

    for (int i = 1; i < r; i++)
    {
        for (int j = 1; j < c; j++)
        {
            // If current cell has no obstacle
            if (A[i][j] == 0)
            {

                A[i][j] = A[i - 1][j] + A[i][j - 1];
            }
            else
            {
                // No ways to reach at this index
                A[i][j] = 0;
            }
        }
    }

    // returing the bottom right
    // corner of Grid
    return A[r - 1][c-1];
}



// Driver code
int main()
{
   vector<vector<int>> arr = { { 0, 0, 0 },
                             { 0, 1, 0 },
                             { 0, 0, 0 } };

   cout<<uniquePathsWithObstacles1(arr)<<"\n";
}
