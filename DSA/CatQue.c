#include<stdio.h>
#define N 20
int front = -1, rear = -1, Q[N], ele, temp;
void enQ();
void deQ();
void display();
void sort();
void catagorize();

void main(){
	int ch;
	printf("\t\t\tQueue Operation\n");
	while(1){
		printf("\nEnter your choice :\n1. Enqueue\t2. Dequeue\t3. Display\t4. Sort\t5. Catagorize\t6.Exit :");
		scanf("%d",&ch);
		switch(ch){
			case 1: enQ(); 
				break;
			case 2: deQ(); 
				break;
			case 3: display(); 
				break;
			case 4: sort(); 
				break;
			case 5: catagorize();
				break;
			case 6: return;
				break;
		}
	}
}

void enQ(){
	if(rear == (N - 1))
		printf("Overflow\n");
	else{
		printf("Enter element to be inserted range(1 to 100):");
		scanf("%d",&ele);
		if(front == -1)
			front++;
		rear++;
		Q[rear] = ele;
	}
}

void deQ(){
	if(rear == - 1 || front > rear)
		printf("Underflow\n");
	else{
		printf("%d has been deleted\n",Q[front]);
		front++;
	}
}

void display(){
	if(rear == - 1 || front > rear)
		printf("Empty Queue\n");
	else{
		printf("Your Queue Elements are : \n");
		for(int i = front; i <= rear; i++)
			printf("%d ",Q[i]);
	}
}

void sort(){
	for(int i = 0; i< N; i++){
		for(int j = 1; j< N - i; j++){
			if(Q[j] < Q[j - 1]){
				temp = Q[j];
				Q[j] = Q[j - 1];
				Q[j -1] = temp;
				
			}
		}
	}
}

void catagorize(){
	if(rear == - 1 || front > rear)
		printf("Empty Queue\n");
	else{
		printf("Your Queue Elements after Catagorizing : \n");
		printf("\nGroup 1 less than 10 : ");
		for(int i = front; i <= rear; i++){
			if(Q[i] < 10)
				printf("%d ",Q[i]);
		}	
		printf("\nGroup 2 between 10 and 19 : ");
		for(int i = front; i <= rear; i++){
			if(Q[i] >= 10 && Q[i] <= 19)
				printf("%d ",Q[i]);
		}
		printf("\nGroup 3 between 20 and 29 : ");
		for(int i = front; i <= rear; i++){
			if(Q[i] >= 20 && Q[i] <= 29)
				printf("%d ",Q[i]);
		}
		printf("\nGroup 4 between 30 and 99 : ");
		for(int i = front; i <= rear; i++){
			if(Q[i] >= 30 && Q[i] <= 99)
				printf("%d ",Q[i]);
		}
	}
}

