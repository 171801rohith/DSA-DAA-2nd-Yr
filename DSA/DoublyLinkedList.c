#include<stdio.h>
#include<stdlib.h>
void createdll();
void displaydll();
void insertEnd();
void insertBeg();
void deleteBeg();
void deleteEnd();


struct node {
	char usn[12];
	char name[20];
	char dept[5];
	long ph_no;
	int mark[3];
	struct node *next;
	struct node *prev;
};
struct node *head = 0, *tail, *newnode;
int count = 0;
void main(){
	int ch;
	while(1){
		printf("\nEnter your choice:\n1. CreateDLL\t2. Display\t3. Insert at End\t4. Delete at End\t5. Insert at Beginning\t6. Delete at Beginning\t7. Length of DLL\t8. Exit :");
		scanf("%d", &ch);
		switch(ch){
			case 1: createdll();
				break;
			case 2: displaydll();
				break;
			case 3: insertEnd();
				break;
			case 4: deleteEnd();
				break;
			case 5: insertBeg();
				break;
			case 6: deleteBeg();
				break;
			case 7: printf("Length of DLL = %d", count);
				break;
			case 8: return;
		}
	}
}

void createdll(){
	newnode = (struct node *)malloc(sizeof(struct node));
	printf("Enter student details :\n");
	printf("Enter name : ");
	scanf("%s", newnode->name);
	printf("Enter USN : ");
	scanf("%s", newnode->usn);
	printf("Enter department : ");
	scanf("%s", newnode->dept);
	for(int i = 0; i<3; i++){
		printf("Enter mark[%d] : ", (i + 1));
		scanf("%d", &newnode->mark[i]);
	}
	printf("Enter phone number : ");
	scanf("%ld", &newnode->ph_no);
	newnode->next = 0;
	newnode->prev = 0;
	if(head == 0)
		tail = head = newnode;
	else{
		tail->next = newnode;
		newnode->prev = tail;
		tail = newnode;
	}
	count++;
}

void displaydll(){
	struct node *temp = head;
		printf("Student details :\n");
	while(temp != 0){
		int total = 0;
		printf("-----------------------------\n");
		printf("NAME = %s\n", temp->name);
		printf("USN = %s\n", temp->usn);
		printf("DEPARTMENT = %s\n", temp->dept);
		for(int i = 0; i<3; i++){
			printf("MARK[%d] = %d\t", (i + 1), temp->mark[i]);
			total += temp->mark[i];
		}
		printf("\n");
		printf("PHONE NUMBER = %ld\n", temp->ph_no);
		printf("TOTAL MARKS = %d\n", total);
		printf("AVERAGE MARKS = %f\n", (total / 3.0));
		temp = temp->next;
		printf("-----------------------------\n");
	}
	printf("Number of Students = %d\n", count);
}

void insertEnd(){
	newnode = (struct node *)malloc(sizeof(struct node));
	printf("Enter student details :\n");
	printf("Enter name : ");
	scanf("%s", newnode->name);
	printf("Enter USN : ");
	scanf("%s", newnode->usn);
	printf("Enter department : ");
	scanf("%s", newnode->dept);
	for(int i = 0; i<3; i++){
		printf("Enter mark[%d] : ", (i + 1));
		scanf("%d", &newnode->mark[i]);
	}
	printf("Enter phone number : ");
	scanf("%ld", &newnode->ph_no);
	newnode->next = 0;
	newnode->prev = tail;
	tail->next = newnode;
	tail = newnode;
	count++;
}

void insertBeg(){
	newnode = (struct node *)malloc(sizeof(struct node));
	printf("Enter student details :\n");
	printf("Enter name : ");
	scanf("%s", newnode->name);
	printf("Enter USN : ");
	scanf("%s", newnode->usn);
	printf("Enter department : ");
	scanf("%s", newnode->dept);
	for(int i = 0; i<3; i++){
		printf("Enter mark[%d] : ", (i + 1));
		scanf("%d", &newnode->mark[i]);
	}
	printf("Enter phone number : ");
	scanf("%ld", &newnode->ph_no);
	newnode->next = head;
	newnode->prev = 0;
	head->prev = newnode;
	head = newnode;
	count++;
}

void deleteBeg(){
	struct node *temp = head;
	if(head == 0)
		printf("Empty DLL\n");
	else if(head == tail){
		head = 0;
		free(tail);
	}
	else{
		head = head->next;
		head->prev = 0;
		free(temp);
		count--;
	}
}

void deleteEnd(){
	struct node *temp = tail;
	if(head == 0)
		printf("Empty DLL\n");
	else if(head == tail){
		head = 0;
		free(tail);
	}
	else{
		tail = tail->prev;
		tail->next = 0;
		free(temp);
		count--;
	}
}




