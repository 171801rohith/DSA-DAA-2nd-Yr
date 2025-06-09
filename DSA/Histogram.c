#include<stdio.h>
int a[100], n,i,j;
int freq[10]={0};
void storedata();
void display();
void makefreq();
void makehisto();

void main(){
	int choice;
	while(1){
		printf("\nFREQUENCY HISTOGRAM\n");
		printf("Enter your choice\n1.Store\t\t2.Display\t\t3.MakeFrequency\t\t4.MakeHistogram\t\t5.Exit\n");
		scanf("%d",&choice);
		switch(choice){
			case 1 :  storedata();
				break;
			case 2 :  display();
				break;
			case 3 :  makefreq();
				break;
			case 4 :  makehisto();
				break;
			case 5 : return;
				break;
			default : printf("\nINVALID CHOICE");
		}
	}
}

void storedata(){
	printf("\nEnetr no of elemnets :");
	scanf("%d",&n);
	printf("\nEnetr %d elements ranging from 0 to 9 :",n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);	
}

void display(){
	printf("\bYour %d elements ranging from 0 to 9 :",n);
	for(i=0;i<n;i++)
		printf("%d  ",a[i]);
}

void makefreq(){
	for(i=0;i<10;i++)
		for(j=0;j<n;j++)
			if(a[j] == i)
				freq[i] += 1;
}

void makehisto(){
	for(i=0;i<10;i++){
		printf("\n[%d] ",i);
	for(j=0;j<freq[i];j++)
		printf("* ");
	}	
}


