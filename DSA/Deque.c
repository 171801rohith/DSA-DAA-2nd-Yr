#include<stdio.h>
#define N 5
int front = -1, rear = -1, DQ[N], ele;
void inF();
void inR();
void delF();
void delR();
void display();
void getF();
void getR();

void main(){
	int ch;
	printf("\t\t\tDeque Operation\n");
	while(1){
		printf("\nEnter your choice :\n1. InsertFront\t2. InsertRear\t3. DeleteFront\t4. DeleteRear\t5. Display\t6. getFront\t7.getRear\t8. Exit :");
		scanf("%d",&ch);
		switch(ch){
			case 1: inF(); 
				break;
			case 2: inR(); 
				break;
			case 3: delF(); 
				break;
			case 4: delR(); 
				break;
			case 5: display(); 
				break;
			case 6: getF(); 
				break;
			case 7: getR(); 
				break;
			case 8: return;
				break;
		}
	}
}

void inF(){
	printf("Enter the element : ");
	scanf("%d",&ele);
	if((front == 0 && rear == N - 1) || (front == rear + 1))
		printf("Overflow\n");
	else if(rear == -1 && front == -1){
		front = rear = 0;
		DQ[front] = ele;
	}else if(front == 0){
		front = N - 1;
		DQ[front] = ele;
	}else {
		front--;
		DQ[front] = ele;		
	}	
}

void inR(){
	printf("Enter the element : ");
	scanf("%d",&ele);
	if((front == 0 && rear == N - 1) || (front == rear + 1))
		printf("Overflow\n");
	else if(rear == -1 && front == -1){
		front = rear = 0;
		DQ[rear] = ele;
	} else if(rear == N - 1){
		rear = 0;
		DQ[rear] = ele;
	}else{
		rear++;
		DQ[rear] = ele;
	}

}

void delF(){
	if (rear == -1 && front == -1)
		printf("Underflow\n");	
	else if(front == rear){
		printf("%d has been deleted", DQ[front]);
		front = rear = -1;
	}else if(front == N - 1){
		printf("%d has been deleted", DQ[front]);
		front = 0;
	}else{
		printf("%d has been deleted", DQ[front]);
		front++;
	}
}

void delR(){
	if (rear == -1 && front == -1)
		printf("Underflow\n");
	else if(front == rear){
		printf("%d has been deleted", DQ[rear]);
		front = rear = -1;
	}else if(rear == 0){
		printf("%d has been deleted", DQ[rear]);
		rear = N - 1;
	}else{
		printf("%d has been deleted", DQ[rear]);
		rear--;
	}
}

void display(){
	int i = front;
	if (rear == -1 && front == -1)
		printf("Empty Queue\n");
	else{
		while(i != rear ){
		printf("%d ",DQ[i]);
		i = (i + 1) % N;
		}	
		printf("%d ",DQ[rear]);
	}
}

void getF(){
	if (rear == -1 && front == -1)
		printf("Empty Queue\n");
	else
		printf("Front element is %d",DQ[front]);
}

void getR(){
	if (rear == -1 && front == -1)
		printf("Empty Queue\n");
	else
		printf("Rear element is %d",DQ[rear]);
}


