#include<stdio.h>
#include<stdlib.h>
int key, m, n, *ht, hi, elec, flag;

void createht(){
	int i;
	ht = (int *)malloc(m * sizeof(int));
	if(m == 0){
		printf("Unable to create the hash table\n");
		exit(0);
	} 
	else{
		for(i = 0; i < m; i++)
			ht[i] = -1;	
	}
}

void insertht(int key){
	hi = key % m;
	while(ht[hi] != -1){
		hi = (hi + 1) % m;
		flag = 1;	
	}
	if(flag){
		printf("Collision detected and avoided by linear probing\n");
		flag = 0;	
	}
	ht[hi] = key;
	elec++;
}

void displayht(){
	int i;
	if(elec == 0){
		printf("\n Empty hash table\n");
		exit(0);
	}	
	printf("Hash table contents are \n");
	for(i = 0; i < m; i++)
		printf("[%d]-->%d\n", i, ht[i]);
}

void main(){
	int i;
	printf("Enter number of Employees records :");
	scanf("%d", &n);
	printf("Enter 2 digits memory location :");
	scanf("%d", &m);
	createht();	
	printf("Enter 4 digits key values of Employees records :");
	for(i = 0; i < n; i++){
		scanf("%d", &key);
		if(elec == m){
			printf("Hash Table is full\n");
			return;
		}
		insertht(key);	
	}
	displayht();
}
