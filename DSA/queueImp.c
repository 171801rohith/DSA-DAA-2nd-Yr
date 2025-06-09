#include<stdio.h>
#define N 7

int Queue[N];
int ele, front = -1, rear = -1;
void Enqueue();
void Dequeue();
void Display();

void main(){
	int ch;
	while(1){
		printf("\nQUEUE OPERATION\n");
		printf("\n1.ENQUEUE\t2.DEQUEUE\t3.DISPLAY\t4.EXIT\n");
		scanf("%d",&ch);
		switch(ch){
			case 1:Enqueue();
				break;
			case 2:Dequeue();
				break;
			case 3:Display();
				break;
			case 4:return;
				break;
		}
	}
}

void Enqueue(){
	if(rear == (N - 1))
		printf("Overflow\n");
	else{
		printf("Enter element to be inserted :");
		scanf("%d",&ele);
		if(front == -1)
			front++;
		rear++;
		Queue[rear] = ele;
	}
}

void Dequeue(){
	if(rear == - 1 || front > rear)
		printf("Underflow\n");
	else{
		printf("%d has been deleted\n",Queue[front]);
		front++;
	}
}

void Display(){
	if(rear == - 1 || front > rear)
		printf("Empty Queue\n");
	else{
		printf("Your Queue Elements are : \n");
		for(int i = front; i <= rear; i++)
			printf("%d ",Queue[i]);
	}
}
