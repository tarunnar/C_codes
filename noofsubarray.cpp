#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int size,m,result=0;
	int arr[1000],i;
	cin >> size;
	for (i = 0; i < size; ++i)
	{
		cin >> arr[i];
	}
	cin >> m;
	int start=0,end=0,noofodds=0;
	while(start<=end || end<size){
		if (noofodds<m)
		{
			while(noofodds<m){
				if (arr[end]%2==1)
				{
					noofodds++;
				}
				end++;
			}
		}
		if (noofodds>m)
		{
			while(noofodds>m){
				if (arr[start]%2)
				{
					noofodds-=1;
				}
				start++;
			}
		}
		if (noofodds==m)
		{
			result+=1;
			while(arr[start]%2==0){
				start++;
				result+=1;
			}
		}
		if (arr[end]%2==1)
		{
			noofodds+=1;

		}
		if (arr[start]%2)
		{
			noofodds-=1;
			start++;
		}
		printf("start=%d end=%d result=%d noofodds=%d\n",start,end,result,noofodds );
	}
	return 0;
}