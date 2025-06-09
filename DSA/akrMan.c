#include<stdio.h>

int akr(int m, int n){
	if( m == 0)
		return n + 1;
	else if( m > 0 && n == 0 )
		return akr(m - 1, 1);
	else if( m > 0 && n > 0)
		return akr(m - 1, akr(m, n - 1));
}

void main(){
	int m, n;
	printf("Enter m and n value:");
	scanf("%d%d",&m,&n);
	printf("\nAkermann result A(%d, %d) = %d\n",m, n, akr(m, n));
}
