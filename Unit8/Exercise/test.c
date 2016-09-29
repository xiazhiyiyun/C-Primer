#include <stdio.h>

int main()
{
	int j;

	int i = 8;
	double d = 10.0;

	double *q = &i;
	printf("%f\n",*q );
	printf("%x\n", q);


	int *p1 = &i;
	double *p2 = &d;
	printf("*p1 = %d\n",*p1);
	printf("*p2 = %f\n",*p2);

	void *p4 = p2;
	printf("%d\n",(int *)p4 );

	void *p3 = p1;
	p2 = p3;
	printf("*p2 = %f\n",*p2);
	printf("%x\n", p2);

	char *p5 = p3;
	for(j = 0; j < 4; j++)
	{
		printf("%x,%c\n",p5,*(p5++) );
	}

	printf("%x\n", p2+1);



}