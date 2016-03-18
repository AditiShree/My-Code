#include<stdio.h>
int main()
{
	int i,j,sum=0;
	for(i=3;i<1000;i++)
	{
		if((i%3==0)||(i%5==0))
		{
			sum=sum+i;
		}
	}
	printf("sum is %d",sum);
}