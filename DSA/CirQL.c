#include<stdio.h>
#define N 5
int front = -1, rear = -1;
char Q[N], ele;
void enQ();
void deQ();
void display();
void peek();

void main(){
	int ch;
	printf("\t\t\tCicular Queue Operation\n");
	while(1){
		printf("\nEnter your choice :\n1. Enqueue\t2. Dequeue\t3. Display\t4. Exit :");
		scanf("%d",&ch);
		switch(ch){
			case 1: enQ(); 
				break;
			case 2: deQ(); 
				break;
			case 3: display(); 
				break;
			case 4: return;
				break;
		}
	}
}

void enQ(){
	printf("Enter the element : ");
	scanf("%*c%c",&ele);
	if(rear == -1 && front == -1){
		front = rear = 0;
		Q[rear] = ele;
	}else if((rear + 1) % N == front)
		printf("Overflow\n");
	else{
		rear = (rear + 1) % N;
		Q[rear] = ele;
	}
}

void deQ(){
	if (rear == -1 && front == -1)
		printf("Underflow\n");
	else if(front == rear){
		printf("%c has been deleted", Q[front]);
		front = rear = -1;
	}else{
		printf("%c has been deleted", Q[front]);
		front = (front + 1) % N;
	}
}

void display(){
	int i = front;
	if (rear == -1 && front == -1)
		printf("Empty Queue\n");
	else{
		while(i != rear){
		printf("%c ",Q[i]);
		i = (i + 1) % N;
		}
		printf("%c ",Q[rear]);
	}
}
