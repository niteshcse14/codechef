#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k,i,caps=0,low=0;
		scanf("%d %d",&n,&k);
		char str[101];
		scanf("%s",str);
		for(i=0;i<n;i++)
		{
			if(str[i]>=65 && str[i]<=90)
				caps++;
			else
				low++;
		}
		//printf("%d %d\n",low,caps);
		if(k>=caps && k>=low)
		printf("both\n");
		else if(k>=caps && k<low)
		printf("chef\n");
		else if(k<caps && k>=low)
		printf("brother\n");
		else
		printf("none\n");
		
	}
} 