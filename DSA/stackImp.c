#include<stdio.h>
#define SIZE 7
int stack[SIZE];
int ele, top=-1;
void push();
void pop();
void display();

void main(){
	int ch;
	while(1){
		printf("\nSTACK OPERATION\n");
		printf("\n1.PUSH\t2.POP\t3.DISPLAY\t4.EXIT\n");
		scanf("%d",&ch);
		switch(ch){
			case 1:push();
				break;
			case 2:pop();
				break;
			case 3:display();
				break;
			case 4:return;
				break;
		}
	}
}

void push(){
	printf("\nEnter a element you want to insert:");
	scanf("%d",&ele);
	if(top == SIZE-1)
		printf("\nOVERFLOW\n");
	else{
		top++;
		stack[top]=ele;
	}
}

void pop(){
	if(top == -1)
		printf("\nUNDERFLOW\n");
	else{
		printf("\n Element %d has been deleted",stack[top]);
		top--;
	}
}

void display(){
	printf("\nYour STACK ELEMENTS are :\n");
	if(top == -1)
		printf("\nEMPTY STACK :(\n");
	else{
		for(int i = top;i>=0;i--)
		printf("%d  ",stack[i]);
	}		
}


