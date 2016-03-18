/*

2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

What is the sum of the digits of the number 2^1000?
*/

#include<stdio.h>
#include<math.h>
int main()
{
	double sum=0,r;
	double n,i=10;
	n=pow(2,100);
	while(n)
	{
		r=n%i;
		sum=sum+r;
		n=n/10;
	}
	printf("sum is   %e\n",sum);


}