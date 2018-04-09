#include <stdio.h>
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,i;
		scanf("%d",&n);
		int fingers[n];
		int glove_sheaths[n];
		for (i = 0; i < n; ++i)
		{
			scanf("%d",&fingers[i]);
 
		}
		for (i = 0; i < n; ++i)
		{
			scanf("%d",&glove_sheaths[i]);
		}
		int flag1=1,flag2=1;
		for (i = 0; i < n; ++i)
		{
			if (glove_sheaths[i]<fingers[i])
			{
				flag1=0;
				break;
			}
		}
		
		for (i = 0; i < n; ++i)
		{
			if (glove_sheaths[n-i-1]<fingers[i])
			{
				flag2=0;
				break;	
			}
		}
		if (flag2==1 && flag1==1)
		{
			printf("both\n");
		}
		else if (flag2==1)
		{
			printf("back\n");
		}
		else if (flag1==1)
		{
			printf("front\n");
		}
		else
		{
			printf("none\n");
		}
	}
	return 0;
}