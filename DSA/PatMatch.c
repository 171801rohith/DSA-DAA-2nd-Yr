#include<stdio.h>
#include<string.h>
char str[100],pat[50],rep[50],ans[100];
int m,i,k,j,c,flag=0;
void stringmatch(){
	m=i=j=c=0;
	while(str[c]!='\0'){
		if(str[m] == pat[i]){
			i++;
			m++;
			if(pat[i] == '\0'){
				flag = 1;
				for(k=0;rep[k]!='\0';k++,j++)
					ans[j]=rep[k];
				i=0;
				c=m;
			}
		}else{
			ans[j] = str[c];
			j++;
			c++;
			i=0;
			m=c;
		}
	}
	ans[j]='\0';
}

void main(){
	printf("\nPATTERN MATCHING");
	printf("\nEnter main string: ");
	gets(str);
	printf("Enter pattern string: ");
	gets(pat);
	printf("Enter replace string: ");
	gets(rep);
	stringmatch();
	if(flag == 1)
		printf("\nThe Resultant String : %s\n",ans);
	else
		printf("\nPattern '%s' not found.\n",pat);
}
