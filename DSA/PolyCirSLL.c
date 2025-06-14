#include<stdlib.h>
#include<math.h>
#include<stdio.h>

struct node{
	int coef, expox, expoy, expoz;
	struct node *link;
};
typedef struct node *NODE;

NODE createnode(int coef, int ex, int ey, int ez){
	NODE temp;
	temp = (NODE)malloc(sizeof(struct node));
	temp->coef = coef;
	temp->expox = ex;
	temp->expoy = ey;
	temp->expoz = ez;
	temp->link = NULL;
	return temp;
}

NODE createheadnode(){
	NODE temp;
	temp = (NODE)malloc(sizeof(struct node));
	temp->coef = 0;
	temp->expox = -1;
	temp->expoy = -1;
	temp->expoz = -1;
	temp->link = temp;
	return temp;
}

void insert_rear(int coef, int ex, int ey, int ez, NODE head){
	NODE temp, cur;
	temp = createnode(coef, ex, ey, ez);
	if(head->link == head)
		head->link = temp;
	else{
		cur = head;
		while(cur->link != head){
			cur = cur->link;
		}
		cur->link = temp;
	}
	temp->link = head;
	head->coef = (head->coef) + 1;
}

void createpoly(NODE poly){
	int i, n, coef, ex, ey, ez;
	printf("Enter the number of terms in the polynomial :");
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		printf("Enter coefficient :");
		scanf("%d", &coef);
		printf("Enter the exponenr of (x, y, z) :");
		scanf("%d%d%d", &ex, &ey, &ez);
		insert_rear(coef, ex, ey, ez, poly);
	}
}

void display(NODE head){
	NODE cur;
	if(head->link == head)
		printf("Empty LIST :(\n");
	else{
		cur = head->link;
		while(cur != head){
			if(cur->coef < 0)
				printf("%dx^%dy^%dz^%d", cur->coef, cur->expox, cur->expoy, cur->expoz);
			else
				printf("+%dx^%dy^%dz^%d", cur->coef, cur->expox, cur->expoy, cur->expoz);
			cur = cur->link;		
		}
		printf("\nNumber of terms = %d\n", head->coef);
	}
}

double evaluate(int x, int y, int z, NODE head){
	double result = 0;
	NODE cur;
	if(head->link == head)
		printf("Empty LIST :(\n");
	else{
		cur = head->link;
		while(cur != head){
			result += cur->coef * pow(x, cur->expox) * pow(y, cur->expoy) * pow(z, cur->expoz);
			cur = cur->link;		
		}
	}
	return result;
}

NODE polyadd(NODE a, NODE b){
	NODE c, starta, startb;
	int sum = 0;
	starta = a;
	startb = b;
	a = a->link;
	b = b->link;
	c = createheadnode();
	while((starta != a) && (startb != b)){
		if((a->expox == b->expox) && (a->expoy == b->expoy) && (a->expoz == b->expoz)){
			sum = a->coef + b->coef;
			insert_rear(sum, a->expox, a->expoy, a->expoz, c);
			a = a->link;
			b = b->link;
		}else if(a->expox > b->expox){
			insert_rear(a->coef, a->expox, a->expoy, a->expoz, c);
			a = a->link;
		}else if((a->expox == b->expox) && (a->expoy > b->expoy)){
			insert_rear(a->coef, a->expox, a->expoy, a->expoz, c);
			a = a->link;
		}else if((a->expox == b->expox) && (a->expoy == b->expoy) && (a->expoz > b->expoz)){
			insert_rear(a->coef, a->expox, a->expoy, a->expoz, c);
			a = a->link;
		}else{
			insert_rear(b->coef, b->expox, b->expoy, b->expoz, c);
			b = b->link;
		}
	}
	while(a != starta){
		insert_rear(a->coef, a->expox, a->expoy, a->expoz, c);
		a = a->link;
	}
	while(b != startb){
		insert_rear(b->coef, b->expox, b->expoy, b->expoz, c);
		b = b->link;
	}
	return c;
}

void main(){
	int x, y, z;
	double eval = 0;
	NODE poly1 = NULL;
	NODE poly2 = NULL;
	NODE polysum = NULL;
	printf("\n**********Evaluation of POLYNOMIAL**********\n");
	poly1 = createheadnode();
	createpoly(poly1);
	printf("Polynomial is :");
	display(poly1);
	printf("\n");
	printf("Enter values of (x, y, z) :");
	scanf("%d%d%d",&x, &y, &z);
	eval = evaluate(x, y, z, poly1);
	printf("Polynomial Evaluation is %.2f\n", eval);
	printf("\n**********Addition of 2 POLYNOMIAL**********\n");
	poly1 = createheadnode();
	createpoly(poly1);
	printf("Polynomial 1 is :");
	display(poly1);
	printf("\n");
	poly2 = createheadnode();
	createpoly(poly2);
	printf("Polynomial 2 is :");
	display(poly2);
	printf("\n");
	polysum = polyadd(poly1, poly2);
	printf("Polynomial Sum is :");
	display(polysum);
	printf("\n");
}	
