
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
	FILE *fp;
	int prod=1,count,c[1000];
	int i,j,n; 
	char filename[14],a[1000];
	//printf("enter file name to e opened\n");
	//scanf("%s",filename);
	fp=fopen("apple.txt","r");
	for(i=0;i<1000;i++){
		a[i]=fgetc(fp);
		c[i]=a[i]-48;
	
	}
	/*for(i=0;i<4;i++){
		printf("%d\n",c[i] );
	}*/
	int l,tmp=1,str;
	for(l=0;l<997;l++){
		n=1;
		for(j=0;j<13;j++){
			n=n*c[l+j];
		}
		if(n>tmp){
			str=l;
			tmp=n;
		}

	}
		for(j=0;j<13;j++){
			printf("%d\n",c[str+j] );
		}
	
	fclose(fp);

}