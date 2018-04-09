#include <stdio.h>
#include <math.h>
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,h,i,curr;
		scanf("%d%d",&n,&h);
		long long int max_banana=-999999999;
		for (i = 0; i < n; ++i)
		{
			scanf("%d",&curr);
			if (max_banana<curr)
			{
				max_banana=curr;				
			}
		}
		int rounds=(int)ceil((1.0*h)/n);
		//printf("rounds%d\n", rounds);
		long long int result=(long long int)ceil((1.0*max_banana)/rounds);
		printf("%lld\n",result);
	}

	return 0;
}