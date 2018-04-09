#include<stdio.h>
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d",&t);
	while(t--){
		int size;
		scanf("%d",&size);
		int arr[size],i,j,p;
		int res[size];
		for (i = 0; i < size; ++i)
		{
			scanf("%d",&arr[i]);
			res[i]=1;
		}
		long long int ma=-999999999;
		for (i = 0; i < size; ++i)
		{
			for (j = 0; j < i ; ++j)
			{
				if (arr[i]%arr[j]==0 )
				{
					if(res[i]<(res[j]+1))
					{
						res[i]=res[j]+1;
					}
				}
			}
			/*printf("i=%d j=%d ma=%lld\n",i,j,ma);
			for (p = 0; p < size; ++p)
			{
				printf("%d ",res[p] );
			}
			printf("\n");*/
			if(ma<res[i]){
				ma=res[i];
			}
		}
		printf("%lld\n", ma);
	}
	
	return 0;
}