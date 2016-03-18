#include<stdio.h>
int main()
{
	int n,i,sum=0,j,a[10002],count=0,temp=0;
	//printf("enter a no\n");
	//scanf("%d",&n);
	for(n=2;n<10000;n++)
	{
		sum=0;
		for(i=1;i<n;i++)
		{
			if(n%i==0)
			{
				sum+=i;
			}
		}
		a[n-2]=sum;
	}
	for (n = 2; n < 10000; n++)
	{
		for (j = 2; j < 10000; j++)
		{
			if ((a[n-2]==j)&&(a[j-2]==n)&&(n!=j))
			{
				count++;
				temp=temp+n+j;
				
			}

		}
	}
	printf("%d\n",temp/2);
	printf("total no is : %d\n",count );
}