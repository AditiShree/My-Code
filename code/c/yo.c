#include<stdio.h>
int main()
{
int a,b,c,x,y,z;
for(a=1;a<1000;a++)
{
for(b=2;b<1000;b++)
{
c=1000-a-b;
if(a*a + b*b == c*c)
{
x=a;
y=b;
z=c;
}
}
}
printf("%d\t%d\t%d",x,y,z);
return 0;
}
