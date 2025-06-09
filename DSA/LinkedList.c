#include<stdio.h>
#include<stdlib.h>
void create();
void display();
void count();
void insertEnd();
void insertBeg();
void deleteBeg();
void deleteEnd();
void deleteAtPosition();
void insertAtPosition();

struct node {
	int data;
	struct node *next;
};
struct node *head = 0, *temp, *newnode;
int count = 0;
void main(){
	int ch;
	while(1){
		printf("\nEnter your choice:\n1. CreateNode\t2. Display\t3. Insert at Beginning\t4. Insert at End\t5. Delete at Beginning\t6. Delete at End\t7. Insert at Position\t8. Delete at Position\t9. Count\t10. Exit :");
		scanf("%d", &ch);
		switch(ch){
			case 1: create();
				break;
			case 2: display();
				break;
			case 3: display();
				break;
			case 4: display();
				break;
			case 5: display();
				break;
			case 6: display();
				break;
			case 7: display();
				break;
			case 8: display();
				break;
			case 9: count();
				printf("Count Length of SLL = %d", count);
				break;
			case 10: return;
		}
	}
}

void create(){
	newnode = (struct node *)malloc(sizeof(struct node));
	printf("Enter element:");
	scanf("%d", &newnode->data);
	newnode->next = 0;
	if(head == 0)
		temp = head = newnode;
	else{
		temp->next = newnode;
		temp = newnode;
	}
}

void display(){
	struct node *temp1;
	temp1 = head;
	while(temp1 != 0){
		printf("%d ", temp1->data);
		temp1 = temp1->next;
	}
}

void count(){
	struct node *temp1;
	temp1 = head;
	while(temp1 != 0){
		count++;
		temp1 = temp1->next;
	}
}
