#include<stdio.h>
int main()
{
	int i,j,r,sum=0,count;
	for(i=2;i<100000;i++)
	{
		count=0;
		for (j = 1; j <= i; j++)
		{
		//x=i%j;
			if(i%j==0)
			{
				count++;
			}
			
		}
		if(count==2)
		{
			sum=sum+i;

		}
		
	}
	printf("%d",sum);
}