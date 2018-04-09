#include <stdio.h>
int main(int argc, char const *argv[])
{
	int n=21,i,j,p;
	for (i = 1; i <= n; ++i)
	{
		for (j = 1; j <=n; ++j)
		{
			if (i<=(n+1)/2)
			{
				p=i;
			}
			else{
				p=n-i+1;
			}
			if (j<=p)
			{
				printf("%d ",j);
			}
			else if (j>n-p)
			{
				printf("%d ",n+1-j);
			}
			else{
				printf("  ");
			}
		}
		printf("\n");

	}
	return 0;
}