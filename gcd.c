#include<stdio.h>

int gcd(int,int);

int main()
{
	int a,b,res;
	
	printf("Enter the value of a and b: ");
	scanf("%d%d",&a,&b);
	
	res = gcd(a,b);
	
	printf("gcd(%d,%d) = %d\n",a,b,res);
	
	return 0;
}

int gcd(int a,int b)
{
	if(!a) return b;   // if a == 0
	if(!b) return a;   // if b == 0
	
	return gcd(b, a % b);
}
