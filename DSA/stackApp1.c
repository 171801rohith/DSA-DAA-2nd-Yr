#include<stdio.h>
#include<string.h>
#include<math.h>
#define SIZE 100
int stack[SIZE];
int top = -1;
void push(int val);
int pop();
int isOperand(char ch);

void main(){
	char postfix[SIZE],ch;
	int i=0,m,res,op1,op2;
	printf("\nEnter the postfix expression :");
	gets(postfix);
	while(postfix[i]!='\0'){
		ch=postfix[i];
		if(isOperand(ch)==1){
			printf("Enter the value of %c :",ch);
			scanf("%d",&m);
			push(m);
		}else{
			op2=pop();
			op1=pop();
			switch(ch){
				case '+': res=op1+op2;
					push(res);
					break;
				case '-': res=op1-op2;
					push(res);
					break;
				case '*': res=op1*op2;
					push(res);
					break;
				case '/': res=op1/op2;
					push(res);
					break;
				case '%': res=op1%op2;
					push(res);
					break;
				case '^': res= pow(op1,op2);
					push(res);
					break;
			}
		}
		i++;
	}
	res=pop();
	printf("\nTHE RESULT = %d\n",res);
}

void push(int val){
	top++;
	stack[top]=val;
}

int pop(){
	int a = stack[top];
	top--;
	return a;
}

int isOperand(char ch){
	if(ch>='a' && ch<='z' || ch>='A' && ch<='Z')
		return 1;
	else
		return 0;
}


