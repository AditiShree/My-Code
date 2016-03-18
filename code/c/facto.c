#include<stdio.h>
int main()
{
	int i,r,sum=0;
	long long int k=1;
	for (i = 99; i >90 ; i--)
	{
		k=k*i;
	}
   // temp=k;
	printf("%lld\n",k );
	while(k>0)
	{
		r=k%10;
		sum=sum+r;
		k=k/10;
	}
	printf("the sum of no is : %d\n",sum);


}