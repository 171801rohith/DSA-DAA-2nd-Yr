#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define SIZE 20

char stack[SIZE];
int top = -1 ;

void push(char ele){
	stack[++top] = ele;
}

char pop(){
	return stack[top--];
}

int precedence(char ele){
	switch(ele){
		case '#': return 0;
		case '(': return 1;
		case '+':
		case '-': return 2;
		case '*':
		case '/':
		case '%': return 3;
		case '^': return 4;
		default : printf("\n Invalid Expression \n");
			exit(0);
	}
}

void main(){
	char infix[20], postfix[20], ch, ele;
	int i = 0, k = 0, pr;
	printf("Enter infix Expression : ");
	scanf("%s", infix);
	push('#');
	while((ch = infix[i++]) != '\0'){
		if(ch == '(')
			push(ch);
		else if(isalnum(ch))
			postfix[k++] = ch;
		else if(ch == ')'){
			while(stack[top] != '('){
				postfix[k++] = pop();
				if(stack[top] == '#'){
					printf("\n Invalid Expression \n");
					exit(0);
				}			
			}
			ele = pop();
		}else {
			pr = precedence(ch);
			if(ch == '^')
				pr++;
			while(precedence(stack[top])>=pr)
				postfix[k++] = pop();
			push(ch);
		}
	}
	while(stack[top] != '#')
		postfix[k++] = pop();	
	postfix[k] = '\0';
	printf("\n Given Infix Expression : %s\n Postfix Expression : %s \n",infix, postfix);
}
