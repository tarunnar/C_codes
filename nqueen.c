#include <bits/stdc++.h>
using namespace std;
bool  checkifsafe(int grid[][16],int row,int col){
  int i,j;
  //cout << "hi1"<< row<<"," << col << endl;
  for (i = 0; i < row; ++i)
  {
    if(grid[i][col])
    {
      return false;
    }
  }
  //cout << "hi2"<< row<<"," << col << endl;
  for (i = 0; i < col; ++i)
  {
    if(grid[row][i])
    {
      return false;
    }
  }
  
  for (i = row,j=col; i>=0 && j>=0; --i,--j)
  {
    if(grid[i][j])
    {
      return false;
    }
  }
  
  for (i = row,j=col; i>=0 && j<16; --i,++j)
  {
    if(grid[i][j])
    {
      return false;
    }
  }
  return true;
}
bool fill(int grid[][16],int row){
  if (row>=16)
  {
    return true;
  }
  for (int j = 0; j < 16; ++j)
  {
      if (checkifsafe(grid,row,j))
         {
           //cout<< "was safe" << row << "," << j << endl;
            grid[row][j]=1;
            bool res=fill(grid,row+1);
            if (res)
            {
              return true;
            }
            else{
              grid[row][j]=0;
            }        
         }
       
  }
  return false;
}
int main(int argc, char const *argv[])
{
  int grid[16][16]={
                  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}

                  };
  fill(grid,0);
  for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 16; ++j)
    {
       cout << grid[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}