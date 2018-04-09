#include <bits/stdc++.h>
using namespace std;
int solve(int arr[][8],int &count,int x,int y)
{
	cout << "x=" << x << " y=" << y << "count=" << count+1 << endl;
    if (count==64)
    {
    	return 1;
    }
	if (x>=0 && x<8 && y>=0 && y<8 && arr[x][y] ==INT_MIN)
	{		
			count+=1;
			arr[x][y]=count;
			if (solve(arr,count,x+2,y+1))
			{
				return 1;				
			}
			if (solve(arr,count,x+1,y+2))
			{
				return 1;				
			}
			if (solve(arr,count,x-1,y+2))
			{
				return 1;				
			}
			if (solve(arr,count,x-2,y+1))
			{
				return 1;				
			}
			if (solve(arr,count,x-2,y-1))
			{
				return 1;				
			}
			if (solve(arr,count,x-1,y-2))
			{
				return 1;				
			}
			if (solve(arr,count,x+1,y-2))
			{
				return 1;				
			}
			if (solve(arr,count,x+2,y-1))
			{
				return 1;				
			}
			count-=1;
			arr[x][y]=INT_MIN;
			return 0;
	}
	else{
		return 0;
	}
}
 
int main(int argc, char const *argv[])
{
	int arr[8][8],count=0;
	for (int i = 0; i < 8; ++i)
    {
    	for (int j = 0; j < 8; ++j)
    	{
    		arr[i][j] =INT_MIN;
    	}
    }

    solve(arr,count,0,0);
    for (int i = 0; i < 8; ++i)
    {
    	for (int j = 0; j < 8; ++j)
    	{
    		cout << arr[i][j] << " ";
    	}
    	cout << endl;
    }

	return 0;
}