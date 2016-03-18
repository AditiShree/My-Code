#include<stdio.h>
int main()
{
	//int i,j;
	int a[40],sum=0,i,j;
	a[0]=1;
	a[1]=2;
	for(i=2;i<40;i++)
	{
		a[i]=a[i-1]+a[i-2];
		//printf("%ld\n",a[i]);
	}
	for(j=0;a[j]<4000000;j++)
	{	
		if(a[j]%2==0)
		{
			sum=sum+a[j];
		}

	
    }
	printf("the sum is %d",sum);
	
}