#include<stdio.h>
int main()
{
	int  p1=1,p2=2,p5=5,p10=10,p20=20,p50=50,f1=100,f2=200,count=0;
	int   	h,	g	,	f,	e,	  d ,	c,		b,		a;

	for (a = 0; a < 2; a++)
		{
			for (b = 0; b <3 ; b++)
			{
				for (c= 0; c < 5; c++)
				{
					for (d = 0; d < 11; d++)
					{
						for (e = 0; e < 21; e++)
						{
							for (f = 0; f < 41; f++)
							{
								for (g = 0; g < 101; g++)
								{
									for (h = 0; h < 201; h++)
									{
										if (200== a*f2 + b*f1 + c*p50 + d*p20 + e*p10 + f*p5 + g*p2 + h*p1)
										{
											//printf("f2=%d*f2 + %d*f1 + %d*p50 + %d*p20 + %d*p10 + %d*p5 + %d*p2 + %d*p1\n",a,b,c,d,e,f,g,h);
											count++;
										}

									}
								}
							}
						}
					}
				}
			}
		}	
		printf("total count is: %d\n",count);	
}