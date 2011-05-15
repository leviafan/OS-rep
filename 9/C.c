#include <stdio.h>
extern int sum(int,int);
int main(){
	int a=2,b=3,val;
	val=sum (a,b);
	printf ("%d + %d = %d\n",a,b,val);
	return 0;
}
