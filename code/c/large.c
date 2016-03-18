#include<stdio.h>

void swap( long int a[],int n)
{
	int i,j;
    long int temp;
	for( i=1;i<n;i++)
	{
		for( j=0;j<n-i;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	printf("largest prd of 13 no is %ld",a[n]);

}

int main()
{
	FILE *ptr;
	long int prod=1,count,a[1000];
	int i,j; 
	char filename[14];
	//printf("enter file name to e opened\n");
	//scanf("%s",filename);
	ptr=fopen("apple.txt","r");
	//while((i=getw(ptr))!=EOF)
	//{
		
	for(i=0;i<1000;i++)
	{
		a[i]=fgetc(ptr);
		prod=1;
		for(j=i;j<i+13;j++)
		{
			prod=prod*j;
		}
		a[i]=prod;
		count++;
	}
	swap(a,count);
    }
    fclose(ptr);

}