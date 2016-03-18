#include<stdio.h>
int main()
{
	int a[]={7,3,5,8,2,9},l,i,j,t;
	for(i=0;i<6;i++)
	{
		for(j=0;j<5-i;j++)
		{
			if(a[j]>a[j+1])
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
			for(l=0;l<6;l++)
		printf("%d\t",a[l]);
	    printf("\n");
		}
	}
	for(i=0;i<6;i++)
		printf("%d\t",a[i]);
}