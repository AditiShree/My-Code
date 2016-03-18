#include<stdio.h>	
int main()
{
	int i,r,temp,sum,final=0;
	//long int i,
	for(i=2;i<355000;i++)
	{
		sum=0;
		temp=i;
		while(temp>0)
		{
			r=temp%10;
			sum=sum + (r*r*r*r*r);
			temp=temp/10;
			//printf("%d\n",sum);
		}
		if(sum==i)
		{
			final=final+i;
			printf("OK checked for %d\n",i);
			//j++;
		//break;

		}	
		
	}
	printf("final sum is %d",final);
}