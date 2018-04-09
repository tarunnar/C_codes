#include <bits/stdc++.h>
#include <string.h>
using namespace std;
void swa(char * a,char * b)
{
	char t=*a;
	*a=*b;
	*b=*a;
}
void permute(char * given,int left,int right){
	if (left==right)
	{
	 	printf("%s\n",given );;
	}
	else{
	 	for (int i = left; i < right; ++i)
	 	{
	 		swa(given+left,given+i);
	 		permute(given,left+1,right);
	 		swa(given+left,given+i);
	 	}
	}
}
int main(int argc, char const *argv[])
{
	char given[100];
	scanf("%s",given);
	permute(given,0,strlen(given)-1);
	return 0;
}